// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

// 
// 
// 
// -> 2
// 
// 
// ... 

fn run() {
    input! {
        n: usize,
        p: [(i32, i32); n],
    }
    // (x, y) -> index
    let mut id = std::collections::BTreeMap::new();
    // (y, x), cnt : y, x 
    let mut down = std::collections::BTreeMap::new();
    for (i, &(x, y)) in p.iter().enumerate() {
        id.insert((x, y), i);
        if y == 0 {
            down.insert((y, x), 1000000);
        } else {
            down.insert((y, x), 0);
        }
    }
    for &(x, y) in p.iter() {
        down.range_mut((y + 1, x - 1)..=(y + 1, x + 1)).for_each(|p| *p.1 += 1);
    }
    let mut set = std::collections::BTreeSet::new();
    for (i, &(x, y)) in p.iter().enumerate() {
        if down.range((y + 1, x - 1)..=(y + 1, x + 1)).all(|p| *p.1 > 1) {
            set.insert(i);
        }
    }
    const MOD: u64 = 1_000_000_009;
    let mut ans = 0u64;
    for it in 0..n {
        let del = if it & 1 == 0 {
            *set.iter().rev().next().unwrap()
        } else {
            *set.iter().next().unwrap()
        };
        set.remove(&del);
        let (x, y) = p[del];
        ans = (ans * n as u64 + del as u64) % MOD;
        down.remove(&(y, x)).unwrap();
        for (&(y, x), _) in down.range((y - 1, x - 1)..=(y - 1, x + 1)) {
            let mut ok = true;
            for q in down.range((y + 1, x - 1)..=(y + 1, x + 1)) {
                ok &= *q.1 > 1;
            }
            if ok {
                set.insert(id[&(x, y)]);
            }
        }
        let mut fix = vec![];
        for (&(y, x), c) in down.range_mut((y + 1, x - 1)..=(y + 1, x + 1)) {
            assert!(*c > 1);
            *c -= 1;
            if *c == 1 {
                fix.push((x, y));
            }
        }
        for (x, y) in fix {
            for (p, _) in down.range((y - 1, x - 1)..=(y - 1, x + 1)) {
                set.remove(&id[&(p.1, p.0)]);
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
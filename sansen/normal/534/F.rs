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

fn run() {
    input! {
        h: usize,
        w: usize,
        a: [usize; h],
        b: [usize; w],
    }
    let mut valid = vec![vec![]; h + 1];
    for (i, valid) in valid.iter_mut().enumerate() {
        for j in 0..(1 << h) {
            let mut cnt = 0;
            let mut x = j;
            while x > 0 {
                cnt += 1;
                let b = x & (!x + 1);
                x += b;
                let b = x & (!x + 1);
                x -= b;
            }
            if cnt == i {
                valid.push(j);
            }
        }
    }
    type Map = std::collections::BTreeMap<(usize, Vec<usize>), (usize, Vec<usize>)>;
    let mut memo = vec![Map::new(); w + 1];
    memo[w].insert((0, vec![0; h]), (0, vec![0; h]));
    for (i, b) in b.iter().enumerate().rev() {
        let mut map = Map::new();
        for (p, _) in memo[i + 1].iter() {
            let (bit, cnt) = p.clone();
            for &v in valid[*b].iter() {
                let mut c = cnt.clone();
                let mut ok = true;
                for (j, (c, a)) in c.iter_mut().zip(a.iter()).enumerate() {
                    if bit >> j & 1 == 0 && v >> j & 1 == 1 {
                        *c += 1;
                    }
                    ok &= *c <= *a && *c + i / 2 + 1 >= *a;
                }
                if ok {
                    map.insert((v, c), (bit, cnt.clone()));
                }
            }
        }
        memo[i] = map;
    }
    let mut pos = (0, vec![]);
    for (p, _) in memo[0].iter() {
        if p.1 == a {
            pos = p.clone();
            break;
        }
    }
    assert!(!pos.1.is_empty());
    let mut ans = vec![];
    for x in 0..w {
        ans.push(pos.0);
        pos = memo[x].get(&pos).unwrap().clone();
    }
    for i in 0..h {
        for a in ans.iter() {
            let c = if *a >> i & 1 == 1 {
                b'*'
            } else {
                b'.'
            };
            print!("{}", c as char);
        }
        println!();
    }
}

fn main() {
    run();
}
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

fn run() {
    input! {
        n: usize,
        t: [u32; n],
    }
    let mut set = std::collections::BTreeSet::new();
    for (i, t) in t.windows(2).enumerate() {
        if i % 2 == 0 && t[0] >= t[1] {
            set.insert(i);
        }
        if i % 2 == 1 && t[0] <= t[1] {
            set.insert(i);
        }
    }
    if set.len() > 4 {
        println!("0");
        return;
    }
    let mut p = std::collections::BTreeSet::new();
    for &x in set.iter() {
        p.insert(x);
        p.insert(x + 1);
    }
    let valid = |p: &[u32], x: usize, y: usize| -> bool {
        let mut set = set.clone();
        set.insert(x);
        set.insert(y);
        if x > 0 {
            set.insert(x - 1);
        }
        if y > 0 {
            set.insert(y - 1);
        }
        for &x in set.iter() {
            if x + 1 >= n {
                continue;
            }
            if x % 2 == 0 && p[x] >= p[x + 1] {
                return false;
            }
            if x % 2 == 1 && p[x] <= p[x + 1] {
                return false;
            }
        }
        true
    };
    let mut t = t;
    let mut ans = 0;
    for (i, &x) in p.iter().enumerate(){
        for &y in p.iter().take(i) {
            t.swap(x, y);
            if valid(&t, x, y) {
                ans += 1;
            }
            t.swap(x, y);
        }
    }
    for &x in p.iter() {
        for i in 0..n {
            if p.contains(&i) {
                continue;
            }
            t.swap(i, x);
            if valid(&t, i, x) {
                ans += 1;
            }
            t.swap(i, x);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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
        n: usize,
        k: usize,
        a: [u64; n],
    }
    let mut dp = vec![(0, 0, 0)];
    let mut next = vec![];
    for mut a in a {
        let mut x = 0;
        let mut y = 0;
        while a % 2 == 0 {
            x += 1;
            a /= 2;
        }
        while a % 5 == 0 {
            y += 1;
            a /= 5;
        }
        next.extend(&dp);
        for (c, p, q) in dp.drain(..) {
            next.push((c + 1, p + x, q + y));
        }
        next.sort_by_key(|p| (p.0, !p.1, !p.2));
        next.dedup_by(|a, b| a.0 == b.0 && a.2 <= b.2);
        std::mem::swap(&mut dp, &mut next);
    }
    let ans = dp.into_iter().filter(|p| p.0 == k).map(|p| p.1.min(p.2)).max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
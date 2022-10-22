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
        n: i64,
        m: usize,
        dir: (i64, i64),
        p: [(i64, i64); m],
    }
    let mut phi = n;
    let mut x = n;
    for i in 2..=n {
        if x % i == 0 {
            phi -= phi / i;
            while x % i == 0 {
                x /= i;
            }
        }
    }
    let mut inv_d = 1 % n;
    let mut r = dir.0 % n;
    phi -= 1;
    while phi > 0 {
        if phi & 1 == 1 {
            inv_d = inv_d * r % n;
        }
        r = r * r % n;
        phi >>= 1;
    }
    let inv = inv_d;
    let mut map = std::collections::BTreeMap::new();
    for (x, y) in p {
        let k = x * inv % n;
        let z = (y - k * dir.1 % n + n) % n;
        assert!(k * dir.0 % n == x && (z + k * dir.1) % n == y);
        *map.entry(z).or_insert(0) += 1;
    }
    let ans = map.into_iter().max_by_key(|p| p.1).unwrap();
    println!("0 {}", ans.0);
}

fn main() {
    run();
}
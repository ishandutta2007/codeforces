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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

fn gcd(mut a: i64, mut b: i64) -> i64 {
    a = a.abs();
    b = b.abs();
    if a == 0 || b == 0 {
        return a + b;
    }
    let mut r = a % b;
    while r > 0 {
        a = b;
        b = r;
        r = a % b;
    }
    b
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let mut p = p;
    p.sort();
    let mut elem = std::collections::HashSet::new();
    let mut cnt = std::collections::HashMap::new();
    let mut ans = 0u64;
    for i in 0..n {
        for j in (i + 1)..n {
            let (a, b) = p[i];
            let (c, d) = p[j];
            let p = c - a;
            let q = d - b;
            let r = q * a - p * b;
            let g = gcd(p, gcd(q, r));
            let l = (p / g, q / g, r / g);
            if elem.contains(&l) {
                continue;
            }
            ans += elem.len() as u64;
            ans -= match cnt.get(&(l.0, l.1)) {
                Some(&v) => v,
                _ => 0,
            };
            elem.insert(l);
            let po = cnt.entry((l.0, l.1)).or_insert(0);
            *po += 1;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
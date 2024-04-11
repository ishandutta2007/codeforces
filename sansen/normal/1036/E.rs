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

use std::cmp::*;

fn gcd(a: i64, b: i64) -> i64 {
    if a < 0 {
        gcd(-a, b)
    } else if b < 0 {
        gcd(a, -b)
    } else if a < b {
        gcd(b, a)
    } else if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        line: [(i64, i64, i64, i64); n],
    }
    let mut ans = 0;
    for (i, &(a, b, c, d)) in line.iter().enumerate() {
        let g = gcd(a - c, b - d);
        ans += g + 1;
        let mut set = std::collections::BTreeSet::new();
        for (_j, &(p, q, r, s)) in line[..i].iter().enumerate() {
            let e = d - b;
            let f = -(c - a);
            let g = s - q;
            let h = -(r - p);
            let x = a * d - b * c;
            let y = p * s - q * r;
            let ga = gcd(e, gcd(f, x));
            let gb = gcd(g, gcd(h, y));
            let (e, f, x) = (e / ga, f / ga, x / ga);
            let (g, h, y) = (g / gb, h / gb, y / gb);
            let det = e * h - f * g;
            if det == 0 {
                continue;
            }
            let nx = h * x - f * y;
            let ny = -g * x + e * y;
            if nx % det.abs() != 0 || ny % det.abs() != 0 {
                continue;
            }
            let z = nx / det;
            let w = ny / det;
            assert!(e * z + f * w == x);
            assert!(g * z + h * w == y);
            if min(a, c) <= z
                && z <= max(a, c)
                && min(b, d) <= w
                && w <= max(b, d)
                && min(p, r) <= z
                && z <= max(p, r)
                && min(q, s) <= w
                && w <= max(q, s)
                && !set.contains(&(z, w))
            {
                set.insert((z, w));
                ans -= 1;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
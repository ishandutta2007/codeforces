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

use std::io::Write;

//  x  y
// t  h 
//  m 
// 
// 
// 
// x_i <= x_j && y_i >= y_j i 
// x_i < x_j && y_i < y_j 
// 
// 
// y_i / x_i >= y_j / x_j && x_i <= x_j 
// 
// 
// 
// h/t   m / t 
// 
// 
// map 
// 
// 
// 2 1
// 1 5 5
// 2 1 11

fn run() {
    input! {
        q: usize,
        m: i64,
        ask: [(u8, i64, i64); q],
    }
    let mut last = 0;
    let mut map = std::collections::BTreeMap::<i64, i64>::new();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (i, (k, a, b)) in ask.into_iter().enumerate() {
        let a = (a + last) % 1_000_000 + 1;
        let b = (b + last) % 1_000_000 + 1;
        if k == 1 {
            let (x, y) = (a, b);
            if map.range(x..).next().map_or(true, |(a, b)| y * *a < *b * x) {
                map.remove(&x);
                while let Some((&a, &b)) = map.range(..x).next_back() {
                    if y * a <= b * x {
                        map.remove(&a);
                    } else {
                        break;
                    }
                }
                loop {
                    let a = map.range(x..).map(|p| (*p.0, *p.1)).take(2).collect::<Vec<_>>();
                    if a.len() < 2 {
                        break;
                    }
                    let (a, b) = (a[0], a[1]);
                    if (a.1 - y) * (b.0 - x) >= (b.1 - y) * (a.0 - x) {
                        map.remove(&a.0);
                    } else {
                        break;
                    }
                }
                map.insert(x, y);
            }
        } else {
            let mut ans = "NO";
            let (t, h) = (a, b);
            let x = (h + t - 1) / t;
            if let Some((&r, &rh)) = map.range(x..).next() {
                let (l, lh) = map.range(..=(h / t)).next_back().map_or((0, 0), |p| (*p.0, *p.1));
                if l == r && lh * t <= m {
                    ans = "YES";
                }
                if l < r && (m - t * rh) * (r - l) >= (rh - lh) * (h - r * t) {
                    ans = "YES";
                }
            }
            writeln!(out, "{}", ans).ok();
            if ans == "YES" {
                last = (i + 1) as i64;
            }
        }
    }
}

fn main() {
    run();
}
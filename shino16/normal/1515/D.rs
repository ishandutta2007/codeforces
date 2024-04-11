use crate::lib::math::abs_diff;
use crate::lib::stdio::*;

fn main() {
    scan!(new cin, t: u32);
    prtln!(new cout);
    for _ in 0..t {
        scan!(from cin, n: usize, mut l: usize, mut r: usize, mut c: [usize1; n]);
        if l < r {
            std::mem::swap(&mut l, &mut r);
            c.reverse();
        }
        let mut lc = vec![0; n];
        let mut rc = vec![0; n];
        for &c in &c[..l] {
            lc[c] += 1;
        }
        for &c in &c[l..] {
            rc[c] += 1;
        }
        let mut ans = 0;
        let mut diff = l - r;
        for c in 0..n {
            if diff >= 2 && lc[c] >= rc[c] + 2 {
                let d = ((lc[c] - rc[c]) / 2).min(diff / 2);
                lc[c] -= d;
                rc[c] += d;
                ans += d;
                diff -= d * 2;
            }
        }
        for c in 0..n {
            if diff > 0 && lc[c] > rc[c] {
                lc[c] -= 1;
                rc[c] += 1;
                ans += 1;
                diff -= 2;
            }
        }
        assert_eq!(diff, 0);
        let mut j = 0;
        for c in 0..n {
            j += abs_diff(lc[c], rc[c]);
        }
        prtln!(to cout, ans + j / 2);
    }
}


pub mod lib {

pub mod math {

pub fn abs_diff<T: PartialOrd + std::ops::Sub<T, Output = T>>(a: T, b: T) -> T {
    if a < b { b - a } else { a - b }
}

}  // mod math

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
pub use crate::scan_value;
pub use  std::io::Write;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::new(out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$v:expr) => { $crate::prtln!(@ $dst, iter=$v, sep=" "); };
    (@ $dst:expr, iter=$v:expr, sep=$sep:expr) => { {
        let mut iter = $v.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for v in iter { std::write!($dst, "{}{}", $sep, v).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, bytes=$v:expr) => {
        $crate::prtln!(@ $dst, std::str::from_utf8(&$v).unwrap());
    };
    (@ $dst:expr, YesNo=$v:expr) => { $crate::prtln!(@ $dst, if $v { "Yes" } else { "No" }); };
    (@ $dst:expr, YESNO=$v:expr) => { $crate::prtln!(@ $dst, if $v { "YES" } else { "NO" }); };
    (@ $dst:expr, $v:expr, no eol) => { std::write!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr) => { std::writeln!($dst, "{}", $v).unwrap(); };
    (@ $dst:expr, $v:expr, $($t:tt)*) => { {
        std::write!($dst, "{} ", $v).unwrap();
        $crate::prtln!(@ $dst, $($t)*);
    } };
    (new $var:ident $(,)?) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    };
    (to $var:ident, $($t:tt)*) => { {
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { {
        $crate::prtln!(new __prtln, $($t)*);
        std::mem::drop(__prtln);
    } };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let mut $var = $crate::scan_value!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::scan_value!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (from $s:expr, $($r:tt)*) => { $crate::scan!(@ $s, $($r)*); };
    (new $var:ident, $($r:tt)*) => {
        let mut __input = String::new();
        std::io::Read::read_to_string(&mut std::io::stdin(), &mut __input).unwrap();
        let $var = &mut __input.split_ascii_whitespace();
        $crate::scan!(@ $var, $($r)*);
    };
    ($($r:tt)*) => { $crate::scan!(new __scan, $($r)*); };
}

#[macro_export]
macro_rules! scan_value {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::scan_value!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::scan_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, bytes) => { $iter.next().expect("no input").as_bytes() };
    ($iter:expr, [u8]) => { $iter.next().expect("no input").as_bytes().to_vec() };
    ($iter:expr, [char]) => { $iter.next().expect("no input").chars().collect::<Vec<_>>() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    (@graph $iter:expr, $n:expr, $m:expr) => { {
        let mut graph = vec![Vec::new(); $n];
        for _ in 0..$m {
            let (a, b) = $crate::scan_value!($iter, (usize1, usize1));
            graph[a].push(b);
            graph[b].push(a);
        }
        ($n, graph)
    } };
    ($iter:expr, graph) => { {
        let (n, m) = $crate::scan_value!($iter, (usize, usize));
        $crate::scan_value!(@graph $iter, n, m)
    } };
    ($iter:expr, tree) => { {
        let n = $crate::scan_value!($iter, usize);
        $crate::scan_value!(@graph $iter, n, n - 1)
    } };
    ($iter:expr, $t:ty) => { $iter.next().expect("no input").parse::<$t>().expect("parse error") };
}

}  // mod stdio

}  // mod lib
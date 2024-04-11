use crate::lib::stdio::*;

fn main() {
    prtln!(new cout);
    scan!(new cin, t: usize);
    for _ in 0..t {
        scan!(from cin, n: usize, mut s: [[u8]; 3]);
        let mut one_more = vec![Vec::new(); 2];
        for i in 0..3 {
            let cnt = s[i].iter().filter(|&&b| b == b'1').count();
            one_more[(cnt >= n) as usize].push(i);
        }
        let flip = one_more[0].len() >= 2;
        if flip {
            for i in 0..3 {
                for b in &mut s[i] {
                    *b ^= b'0' ^ b'1';
                }
            }
            one_more.swap(0, 1);
        }
        one_more[1].sort_by_cached_key(|&i| s[i].iter().filter(|&&b| b == b'1').count());
        one_more[1].reverse();
        let (i, j) = (one_more[1][0], one_more[1][1]);
        let mut push0 = vec![0; s[i].len() + 1];
        let mut done = 0;
        for k in 0..s[j].len() {
            if s[j][k] == b'0' {
                push0[done] += 1;
            } else {
                while s[i][done] != b'1' {
                    done += 1;
                }
                done += 1;
            }
        }
        let mut res = Vec::new();
        for k in 0..=s[i].len() {
            res.extend((0..push0[k]).map(|_| b'0'));
            if k < s[i].len() {
                res.push(s[i][k]);
            }
        }
        if flip {
            for b in &mut res {
                *b ^= b'0' ^ b'1';
            }
        }
        prtln!(to cout, bytes=res);
    }
}


pub mod lib {

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
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
        $crate::prtln!(@ $dst, $($t),*);
    } };
    (new $var:ident $(,)?) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
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
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::scan_value!($iter, $t);
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
    ($iter:expr, bytes) => { $iter.next().unwrap().as_bytes() };
    ($iter:expr, [u8]) => { $iter.next().unwrap().as_bytes().to_vec() };
    ($iter:expr, [char]) => { $iter.next().unwrap().chars().collect::<Vec<_>>() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    (@graph $iter:expr, $n:expr, $m:expr) => { {
        let mut graph = vec![Vec::new(); $n];
        for _ in 0..$m {
            let (a, b) = $crate::scan_value!($iter, (usize1, usize1));
            graph[a].push(b);
            graph[b].push(a);
        }
        graph
    } };
    ($iter:expr, graph) => { {
        let (n, m) = $crate::scan_value!($iter, (usize, usize));
        $crate::scan_value!(@graph $iter, n, m)
    } };
    ($iter:expr, tree) => { {
        let n = $crate::scan_value!($iter, usize);
        $crate::scan_value!(@graph $iter, n, n - 1)
    } };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

}  // mod lib
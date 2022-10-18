use crate::lib::stdio::*;

fn main() {
    prtln!(new cout);
    scan!(new cin, n: usize, p: [usize; n]);
    let mut cand = Vec::new();
    for i in 1..n - 1 {
        if p[i - 1] < p[i] && p[i] > p[i + 1] {
            cand.push(i);
        }
    }
    let mut length = Vec::new();
    for &x in &cand {
        let (mut l, mut r) = (0, 0);
        for y in (0..x).rev() {
            if p[y] < p[y + 1] {
                l += 1;
            } else {
                break;
            }
        }
        for y in x + 1..n {
            if p[y - 1] > p[y] {
                r += 1;
            } else {
                break;
            }
        }
        assert!(l > 0 && r > 0);
        length.push((x, l, r));
    }
    let (mut r0, mut l0) = (0, 0);
    for y in (0..n - 1).rev() {
        if p[y] < p[y + 1] {
            l0 += 1;
        } else {
            break;
        }
    }
    for y in 1..n {
        if p[y - 1] > p[y] {
            r0 += 1;
        } else {
            break;
        }
    }
    if let Some((_, l, r)) = length.iter().copied().max_by_key(|&(_, l, r)| l.max(r)) {
        let (min, max) = (l.min(r), l.max(r));
        if length.iter().filter(|&&(_, l, r)| l.max(r) == max).count() != 1 || max == l0.max(r0) {
            prtln!(to cout, "0");
            return;
        }
        prtln!(to cout, if min == max && min % 2 == 0 { 1 } else { 0 });
    } else {
        prtln!(to cout, "0");
    }
}



pub mod lib {

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
use std::io::{stdout, BufWriter, StdoutLock};

pub fn stdout_buf() -> BufWriter<StdoutLock<'static>> {
    let out = Box::leak(Box::new(stdout()));
    BufWriter::with_capacity(1 << 25, out.lock())
}

#[macro_export]
macro_rules! prtln {
    (@ $dst:expr, iter=$expr:expr) => { $crate::prtln!(@ $dst, iter=$expr, sep=" "); };
    (@ $dst:expr, iter=$expr:expr, sep=$sep:expr) => { {
        let mut iter = $expr.into_iter();
        if let Some(expr) = iter.next() {
            std::write!($dst, "{}", expr).unwrap();
            for expr in iter { std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr) => { std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        std::write!($dst, "{} ", $expr).unwrap();
        $crate::prtln!(@ $dst, $($exprs),*);
    } };
    (new $var:ident) => { let mut $var = stdout_buf(); };
    (new $var:ident, $($t:tt)*) => { {
        $crate::prtln!(new $var);
        $crate::prtln!(to $var, $($t)*);
    } };
    (to $var:ident, $($t:tt)*) => { {
        use std::io::Write;
        $crate::prtln!(@ $var, $($t)*);
    } };
    ($($t:tt)*) => { $crate::prtln!(new __prtln, $($t)*); };
}

#[macro_export]
macro_rules! scan {
    (@ $iter:expr $(,)?) => {};
    (@ $iter:expr, mut $var:ident : $t:tt $($r:tt)*) => {
        let mut $var = $crate::scan_value!($iter, $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
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
    ($iter:expr, [u8]) => { $iter.next().unwrap().as_bytes() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

}  // mod lib
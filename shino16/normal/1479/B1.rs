use crate::lib::slice::upper_bound;
use crate::lib::stdio::*;

fn main() {
    scan!(n: usize, a: [usize; n]);
    let mut pos = vec![Vec::new(); n + 1];
    for i in 0..n {
        pos[a[i]].push(i);
    }
    for i in 0..n + 1 {
        pos[i].push(n);
    }
    let (mut s, mut t) = (Vec::with_capacity(n), Vec::with_capacity(n));
    let (mut x, mut y) = (0, 0);
    for i in 0..n {
        if a[i] == x {
            t.push(a[i]);
            y = a[i];
        } else if a[i] == y {
            s.push(a[i]);
            x = a[i];
        } else {
            let xi = pos[x][upper_bound(&pos[x], &i)];
            let yi = pos[y][upper_bound(&pos[y], &i)];
            if xi < yi {
                s.push(a[i]);
                x = a[i];
            } else {
                t.push(a[i]);
                y = a[i];
            }
        }
    }
    s.dedup();
    t.dedup();
    prtln!(s.len() + t.len());
}



pub mod lib {

pub mod slice {

pub fn partition_point<T, F: FnMut(&T) -> bool>(slice: &[T], mut pred: F) -> usize {
    let (mut l, mut r) = (0, slice.len()); // pred(slice[r]) == false
    while l != r {
        let mid = (l + r) / 2;
        let val = unsafe { slice.get_unchecked(mid) };
        if pred(val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    r
}

pub fn lower_bound<T: Ord>(slice: &[T], v: &T) -> usize {
    partition_point(slice, |x| x < v)
}

pub fn upper_bound<T: Ord>(slice: &[T], v: &T) -> usize {
    partition_point(slice, |x| x <= v)
}

}  // mod slice

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
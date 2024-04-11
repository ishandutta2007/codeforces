use crate::lib::slice::cum::*;
use crate::lib::stdio::*;

fn main() {
    prtln!(new cout);
    scan!(new cin, t: u32);
    for _ in 0..t {
        scan!(from cin, n: usize, u: [usize1; n], s: [u64; n]);
        let mut teams = vec![Vec::new(); n];
        for (&u, &s) in u.iter().zip(s.iter()) {
            teams[u].push(s);
        }
        teams.iter_mut().for_each(|s| s.sort_unstable());
        teams.sort_unstable_by_key(|s| !s.len());
        let mut cums: Vec<_> = teams.iter().map(|s| cuml_sum(s)).collect();
        let mut total: u64 = s.iter().sum();
        let iter = (1..=n).map(|k| {
            while matches!(teams.last(), Some(s) if s.len() < k) {
                teams.pop();
                total -= cums.pop().unwrap().last().unwrap();
            }
            let mut ans = total;
            for cum in &cums {
                ans -= cum[(cum.len() - 1) % k];
            }
            ans
        });
        prtln!(to cout, iter=iter);
    }
}


pub mod lib {

pub mod slice {

pub mod cum {

use crate::lib::zo::*;
use std::ops::Add;

pub fn cuml<T: Copy>(slice: &[T], zero: T, mut op: impl FnMut(T, T) -> T) -> Vec<T> {
    let mut res = Vec::with_capacity(slice.len() + 1);
    let mut tl = zero;
    res.push(tl);
    for &e in slice {
        tl = op(tl, e);
        res.push(tl);
    }
    res
}

pub fn cumr<T: Copy>(slice: &[T], zero: T, mut op: impl FnMut(T, T) -> T) -> Vec<T> {
    let mut res = Vec::with_capacity(slice.len() + 1);
    let mut tl = zero;
    res.push(tl);
    for &e in slice.iter().rev() {
        tl = op(e, tl);
        res.push(tl);
    }
    res.reverse();
    res
}

pub fn cuml_sum<T: Copy + ZeroOne + Add<T, Output = T>>(slice: &[T]) -> Vec<T> {
    cuml(slice, T::ZERO, Add::add)
}

pub fn cumr_sum<T: Copy + ZeroOne + Add<T, Output = T>>(slice: &[T]) -> Vec<T> {
    cumr(slice, T::ZERO, Add::add)
}

}  // mod cum

}  // mod slice

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
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

pub mod zo {

pub trait ZeroOne: Copy + PartialEq {
    const ZERO: Self;
    fn is_zero(self) -> bool {
        self == Self::ZERO
    }
    const ONE: Self;
}

macro_rules! impl_zo {
    ($($t:ty),*) => { $(
        impl ZeroOne for $t {
            const ZERO: Self = 0;
            const ONE: Self = 1;
        }
    )* };
}

impl_zo!(i32, i64, i128, isize, u32, u64, u128, usize);

impl ZeroOne for f64 {
    const ZERO: Self = 0.0;
    const ONE: Self = 1.0;
}

}  // mod zo

}  // mod lib
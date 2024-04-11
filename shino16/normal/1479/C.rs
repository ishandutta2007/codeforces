use crate::lib::bits::Bits;
use crate::lib::stdio::*;

fn main() {
    prtln!(new cout);
    scan!(l: u32, mut r: u32);
    r += 1;
    if l + 1 == r {
        prtln!(to cout, "YES");
        prtln!(to cout, 2, 1);
        prtln!(to cout, 1, 2, l);
        return;
    }
    let k = (r - l - 1).ilog2() as usize;
    let mut graph = vec![Vec::new(); k + 3];

    graph[0].push((1, 1));
    graph[0].push((k + 2, l));
    for j in 2..=k + 2 {
        graph[1].push((j, l));
    }
    for i in 2..=k + 1 {
        for j in i + 1..=k + 2 {
            graph[i].push((j, 1 << (k + 1 - i)));
        }
    }
    for i in 2..=k + 1 {
        if l + 1 + (1 << k) + (1 << (k + 1 - i)) <= r {
            graph[0].push((i, r - (1 << (k + 1 - i)) * 2));
            r -= 1 << (k + 1 - i);
        }
    }

    let m = graph.iter().map(|s| s.len()).sum::<usize>();
    prtln!(to cout, "YES");
    prtln!(to cout, graph.len(), m);
    for i in 0..graph.len() {
        for &(j, c) in &graph[i] {
            prtln!(to cout, i + 1, j + 1, c);
        }
    }
}



pub mod lib {

pub mod bits {

use std::ops::*;

pub trait Bits:
    Sized
    + BitAnd<Output = Self> + BitAndAssign
    + BitOr<Output = Self> + BitOrAssign
    + BitXor<Output = Self> + BitXorAssign
    + Shl<u32, Output = Self> + ShlAssign<u32>
    + Shr<u32, Output = Self> + ShrAssign<u32>
    + Not<Output = Self>
{
    fn trailing_zeros(self) -> u32;
    fn lsb(self) -> Self;
    fn ilog2(self) -> u32;
    fn msb(self) -> Self;
}

macro_rules! impl_bit {
    ($($t:ty),*) => { $(
        impl Bits for $t {
            fn trailing_zeros(self) -> u32 {
                <$t>::trailing_zeros(self)
            }
            fn lsb(self) -> Self {
                self & self.wrapping_neg()
            }
            fn ilog2(self) -> u32 {
                std::mem::size_of::<$t>() as u32 * 8 - self.leading_zeros() - 1
            }
            fn msb(self) -> Self {
                (1 as $t) << self.ilog2()
            }
        }
    )* };
}

impl_bit!(i32, i64, i128, isize, u32, u64, u128, usize);

}  // mod bits

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
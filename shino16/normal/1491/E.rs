use std::cell::RefCell;
use crate::lib::func::rec::*;
use crate::lib::stdio::*;

fn main() {
    scan!(n: usize, uv: [(usize1, usize1); n - 1]);
    let mut g = vec![Vec::new(); n];
    for (i, (u, v)) in uv.into_iter().enumerate() {
        g[u].push((v, i));
        g[v].push((u, i));
    }

    let max_k = 30;
    let mut fib = vec![0; max_k];
    fib[1] = 1;
    for i in 2..max_k {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    let size = RefCell::new(vec![1; n]);
    let removed = RefCell::new(vec![false; n - 1]);
    let find_cut = recurse::<(usize, usize, usize), Option<(usize, usize, usize)>, _>(
        |f, (v, p, k)| {
            size.borrow_mut()[v] = 1;
            for &(to, i) in &g[v] {
                if to == p || removed.borrow()[i] {
                    continue;
                }
                let ch = f((to, v, k));
                if ch.is_some() {
                    return ch;
                }
                let c = size.borrow()[to];
                size.borrow_mut()[v] += c;
                if c == fib[k - 1] {
                    removed.borrow_mut()[i] = true;
                    return Some((to, k - 1, v));
                }
                if c == fib[k - 2] {
                    removed.borrow_mut()[i] = true;
                    return Some((to, k - 2, v));
                }
            }
            None
        },
    );
    let dfs = recurse::<(usize, usize, usize), bool, _>(|f, (v, p, k)| {
        if fib[k] == 1 {
            return true;
        }
        if let Some((u, k2, v)) = find_cut.call((v, p, k)) {
            f((u, v, k2)) && f((v, u, k2 ^ (k - 1) ^ (k - 2)))
        } else {
            false
        }
    });
    for k in 2..max_k {
        if fib[k] == n {
            prtln!(if dfs.call((0, !0, k)) { "Yes" } else { "No" });
            return;
        }
    }
    prtln!("No");
}



pub mod lib {

pub mod func {

pub mod rec {

#[must_use]
pub struct Recurse<F>(F);

impl<F> Recurse<F> {
    pub fn call<Arg, Ret>(&self, arg: Arg) -> Ret
    where
        F: Fn(&dyn Fn(Arg) -> Ret, Arg) -> Ret,
    {
        self.0(&|arg| self.call(arg), arg)
    }
}

pub fn recurse<Arg, Ret, F: Fn(&dyn Fn(Arg) -> Ret, Arg) -> Ret>(f: F) -> Recurse<F> {
    Recurse(f)
}

}  // mod rec

}  // mod func

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
            ::std::write!($dst, "{}", expr).unwrap();
            for expr in iter { ::std::write!($dst, "{}{}", $sep, expr).unwrap(); }
        }
        $crate::prtln!(@ $dst, "");
    } };
    (@ $dst:expr, $expr:expr) => { ::std::writeln!($dst, "{}", $expr).unwrap(); };
    (@ $dst:expr, $expr:expr, $($exprs:expr),*) => { {
        ::std::write!($dst, "{} ", $expr).unwrap();
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
        let s = {
            use ::std::io::Read;
            let mut s = String::new();
            ::std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let $var = &mut s.split_whitespace();
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
    ($iter:expr, bytes) => { $iter.next().as_bytes() };
    ($iter:expr, usize1) => { $crate::scan_value!($iter, usize) - 1 };
    ($iter:expr, $t:ty) => { $iter.next().unwrap().parse::<$t>().unwrap() };
}

}  // mod stdio

}  // mod lib
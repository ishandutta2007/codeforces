use crate::lib::stdio::*;

fn main() {
    scan!(n: usize, m: usize, abc: [(usize, usize, u32); m]);
    let mut graph = vec![Vec::new(); n];
    for (a, b, c) in abc {
        graph[a].push((b, c));
    }
    graph.iter_mut().for_each(|s| s.sort_unstable());
    let mut dist = vec![0_u32; n];
    prtln!(new cout);
    for s in 0..n {
        dist.iter_mut().for_each(|e| *e = !0);
        dist[s] = 0;
        let mut todo = (0, 0);
        loop {
            let mut now = (!0, !0);
            for v in 0..n {
                if (dist[v], v) >= todo {
                    now = now.min((dist[v], v));
                }
            }
            let (d, v) = now;
            if d == !0 {
                break;
            }
            let mut dc = 1 << 30;
            let mut i = 0;
            let dv = (dist[v] % n as u32) as usize;
            let adj = &graph[v];
            for _ in 0..3 {
                for w in 0..n {
                    dc += 1;
                    let (b, c) = unsafe { *adj.get_unchecked(i) };
                    let b = if b + dv >= n { b + dv - n } else { b + dv };
                    if b == w {
                        i += 1;
                        if i == adj.len() {
                            i = 0;
                        }
                        dc = dc.min(c);
                    }
                    unsafe {
                        *dist.get_unchecked_mut(w) = (*dist.get_unchecked(w)).min(d + dc);
                    }
                }
            }
            todo = (dist[v], v + 1);
        }
        prtln!(to cout, iter=&dist);
    }
}


pub mod lib {

pub mod stdio {

pub use crate::prtln;
pub use crate::scan;
pub use crate::parse;
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
        let mut $var = $crate::parse!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        #[allow(non_snake_case)]
        let $var = $crate::parse!($iter.into_iter(), $t);
        $crate::scan!(@ $iter $($r)*)
    };
    (@ $iter:expr, $pat:pat in $t:tt $($r:tt)*) => {
        let $pat = $crate::parse!($iter.into_iter(), $t);
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
macro_rules! parse {
    ($iter:expr, ( $($t:tt),* )) => { ( $($crate::parse!($iter, $t)),* ) };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| $crate::parse!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, bytes) => { $iter.next().expect("no input").as_bytes() };
    ($iter:expr, [u8]) => { $iter.next().expect("no input").as_bytes().to_vec() };
    ($iter:expr, [char]) => { $iter.next().expect("no input").chars().collect::<Vec<_>>() };
    ($iter:expr, usize1) => { $crate::parse!($iter, usize) - 1 };
    (@graph $iter:expr, $n:expr, $m:expr) => { {
        let mut graph = vec![Vec::new(); $n];
        for _ in 0..$m {
            let (a, b) = $crate::parse!($iter, (usize1, usize1));
            graph[a].push(b);
            graph[b].push(a);
        }
        ($n, graph)
    } };
    ($iter:expr, graph) => { {
        let (n, m) = $crate::parse!($iter, (usize, usize));
        $crate::parse!(@graph $iter, n, m)
    } };
    ($iter:expr, tree) => { {
        let n = $crate::parse!($iter, usize);
        $crate::parse!(@graph $iter, n, n - 1)
    } };
    ($iter:expr, $t:ty) => { $iter.next().expect("no input").parse::<$t>().expect("parse error") };
    ($iter:expr) => { $iter.next().expect("no input").parse().expect("parse error") };
}

}  // mod stdio

}  // mod lib
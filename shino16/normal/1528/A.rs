use crate::lib::stdio::*;
use crate::lib::graph::tree::dfs_io::*;

fn main() {
    scan!(new cin, t: u32);
    prtln!(new cout);
    for _ in 0..t {
        scan!(from cin, n: usize, lr: [(i64, i64); n], uv: [(usize1, usize1); n - 1]);
        let mut graph = vec![Vec::new(); n];
        for (u, v) in uv {
            graph[u].push(v);
            graph[v].push(u);
        }
        let mut dp = vec![[0; 2]; n];
        dfs_io(&graph, 0, |v, p| match v {
            In(_) => {}
            Out(v) => if p != !0 {
                dp[p][0] += (dp[v][1] + (lr[p].0 - lr[v].1).abs()).max(dp[v][0] + (lr[p].0 - lr[v].0).abs());
                dp[p][1] += (dp[v][1] + (lr[p].1 - lr[v].1).abs()).max(dp[v][0] + (lr[p].1 - lr[v].0).abs());
            }
        });
        // lib::dbg!(&dp);
        prtln!(to cout, dp[0].iter().max().unwrap());
    }
}


pub mod lib {

pub mod graph {

pub trait Graph {
    fn len(&self) -> usize;
    fn adj(&self, v: usize, f: impl FnMut(usize));
}
impl Graph for Vec<Vec<usize>> {
    fn len(&self) -> usize { self.len() }
    fn adj(&self, v: usize, f: impl FnMut(usize)) {
        self[v].iter().copied().for_each(f);
    }
}

pub mod tree {

// pub mod reroot;
pub use super::*;

pub mod dfs_io {

pub use super::*;

#[derive(Debug)]
pub enum InOut {
    In(usize),
    Out(usize),
}

pub use InOut::*;

pub fn dfs_io(g: &impl Graph, s: usize, mut f: impl FnMut(InOut, usize)) {
    let mut togo = vec![(s, !0)];
    while let Some((v, par)) = togo.pop() {
        if v > !v {
            f(Out(!v), par);
        } else {
            f(In(v), par);
            togo.push((!v, par));
            g.adj(v, |w| {
                if w != par {
                    togo.push((w, v));
                }
            });
        }
    }
}

}  // mod dfs_io

}  // mod tree

}  // mod graph

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
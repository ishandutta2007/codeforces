// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i64;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
        pub fn search(&self, s: T) -> usize {
            debug_assert!(self.sum(self.a.len() - 1) >= s);
            let mut k = 1;
            while 2 * k < self.a.len() {
                k *= 2;
            }
            let mut x = 0;
            let mut w = ZERO;
            while k > 0 {
                if k + x < self.a.len() && w + self.a[x + k] < s {
                    w += self.a[x + k];
                    x += k;
                }
                k >>= 1;
            }
            x + 1
        }
    }
}
// ---------- end fenwick tree ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

//

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
        m: usize,
        p: [(usize1, usize, i64); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut query = vec![vec![]; n];
    for (v, d, x) in p {
        let d = if d > n - 1 {n} else {d + 1};
        query[v].push((d, x));
    }
    let mut bit = fenwick::Tree::new(2 * n);
    let mut ans = vec![0; n];
    enum Operation {
        DFS(usize, usize, usize),
        SUB(usize, usize),
    }
    let mut stack = vec![Operation::DFS(0, 0, 1)];
    while let Some(op) = stack.pop() {
        match op {
            Operation::DFS(v, p, k) => {
                stack.push(Operation::SUB(v, k));
                for &(d, x) in query[v].iter() {
                    bit.add(k, x);
                    bit.add(k + d, -x);
                }
                ans[v] = bit.sum(k);
                for &u in g[v].iter() {
                    if u != p {
                        stack.push(Operation::DFS(u, v, k + 1));
                    }
                }
            },
            Operation::SUB(v, k) => {
                for &(d, x) in query[v].iter() {
                    bit.add(k, -x);
                    bit.add(k + d, x);
                }
            },
        }
    }
    let mut out = String::new();
    for a in ans {
        out.push_str(&format!("{} ", a));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
// ---------- begin Lazy Segment Tree ----------
mod segment_tree {
    pub struct Lazy<T, E, F, G, H> {
        n: usize,
        k: usize,
        a: Vec<(T, E)>,
        e: T,
        id: E,
        f: F,
        g: G,
        h: H,
    }
    #[allow(dead_code)]
    impl<T: Clone, E: Clone, F: Fn(T, T) -> T, G: Fn(T, E) -> T, H: Fn(E, E) -> E> Lazy<T, E, F, G, H> {
        pub fn new(n: usize, e: T, id: E, f: F, g: G, h: H) -> Lazy<T, E, F, G, H> {
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            Lazy {
                n: 1 << k,
                k: k,
                a: vec![(e.clone(), id.clone()); 2 << k],
                e: e,
                id: id,
                f: f,
                g: g,
                h: h,
            }
        }
        pub fn build_by(z: &Vec<T>, e: T, id: E, f: F, g: G, h: H) -> Lazy<T, E, F, G, H> {
            let n = z.len();
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            let mut a = vec![(e.clone(), id.clone()); 2 << k];
            for i in 0..n {
                a[(1 << k) + i].0 = z[i].clone();
            }
            for i in (1..(1 << k)).rev() {
                let l = g(a[2 * i].0.clone(), id.clone());
                let r = g(a[2 * i + 1].0.clone(), id.clone());
                a[i].0 = f(l, r);
            }
            Lazy {
                n: 1 << k,
                k: k,
                a: a,
                e: e,
                id: id,
                f: f,
                g: g,
                h: h,
            }
        }
        fn eval (&self, x: usize) -> T {
            (self.g)(self.a[x].0.clone(), self.a[x].1.clone())
        }
        fn propagate (&mut self, mut x: usize) {
            x += self.n;
            for k in (1..(self.k + 1)).rev() {
                let y = x >> k;
                self.a[2 * y].1 = (self.h)(self.a[2 * y].1.clone(), self.a[y].1.clone());
                self.a[2 * y + 1].1 = (self.h)(self.a[2 * y + 1].1.clone(), self.a[y].1.clone());
                self.a[y].1 = self.id.clone();
                self.a[y].0 = (self.f)(self.eval(2 * y), self.eval(2 * y + 1));
            }
        }
        fn save (&mut self, x: usize) {
            let mut k = (x + self.n) >> 1;
            while k > 0 {
                self.a[k].0 = (self.f)(self.eval(2 * k), self.eval(2 * k + 1));
                k >>= 1;
            }
        }
        pub fn update (&mut self, l: usize, r: usize, p: E) {
            self.propagate(l);
            self.propagate(r - 1);
            let mut x = l + self.n;
            let mut y = r + self.n;
            while x < y {
                if (x & 1) == 1 {
                    self.a[x].1 = (self.h)(self.a[x].1.clone(), p.clone());
                    x += 1;
                }
                if (y & 1) == 1 {
                    y -= 1;
                    self.a[y].1 = (self.h)(self.a[y].1.clone(), p.clone());
                }
                x >>= 1;
                y >>= 1;
            }
            self.save(l);
            self.save(r - 1);
        }
        pub fn find (&mut self, l: usize, r: usize) -> T {
            self.propagate(l);
            self.propagate(r - 1);
            let mut p = self.e.clone();
            let mut q = self.e.clone();
            let mut x = l + self.n;
            let mut y = r + self.n;
            while x < y {
                if (x & 1) == 1 {
                    p = (self.f)(p, self.eval(x));
                    x += 1;
                }
                if (y & 1) == 1 {
                    y -= 1;
                    q = (self.f)(self.eval(y), q);
                }
                x >>= 1;
                y >>= 1;
            }
            (self.f)(p, q)
        }
    }
}
// ---------- end Lazy Segment Tree ----------
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

use std::io::Write;
use std::cmp::{max, min};

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        a: [i32; n],
        p: [(usize1, usize); m],
    }
    let f = |a: (i32, i32), b: (i32, i32)| (min(a.0, b.0), max(a.1, b.1));
    let g = |a: (i32, i32), b| (a.0 + b, a.1 + b);
    let h = |a, b| a + b;
    let mut s = segment_tree::Lazy::build_by(&vec![(0, 0); n], (10_000_000, -10_000_000), 0, f, g, h);
    for i in 0..n {
        s.update(i, i + 1, a[i]);
    }
    let mut inc = vec![vec![]; n + 1];
    let mut dec = vec![vec![]; n + 1];
    for &(l, r) in p.iter() {
        dec[l].push(r);
        inc[r].push(l);
    }
    let mut ans = -1;
    let mut k = 0;
    for i in 0..n {
        for &r in dec[i].iter() {
            s.update(i, r, -1);
        }
        for &l in inc[i].iter() {
            s.update(l, i, 1);
        }
        let (x, y) = s.find(0, n);
        if y - x > ans {
            ans = y - x;
            k = i;
        }
    }
    let mut op = vec![];
    for (i, &(l, r)) in p.iter().enumerate() {
        if l <= k && k < r {
            op.push(i + 1);
        }
    }
    writeln!(out, "{}\n{}", ans, op.len()).unwrap();
    for (i, &v) in op.iter().enumerate() {
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", v).unwrap();
    }
    write!(out, "\n").unwrap();
}

fn main() {
    run();
}
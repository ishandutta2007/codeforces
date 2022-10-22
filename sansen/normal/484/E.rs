// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T, F> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            let a = &mut self.a;
            for k in (1..(self.n)).rev() {
                a[k] = (self.op)(&a[2 * k], &a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            let a = &self.a;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(&p, &q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        h: [u32; n],
        q: usize,
        ask: [(usize1, usize, usize); q],
    }
    let mut ok = vec![1; q];
    let mut ng = vec![1 + *h.iter().max().unwrap(); q];
    let mut h = h.iter().cloned().enumerate().collect::<Vec<_>>();
    h.sort_by_key(|h| h.1);
    loop {
        let mut query = vec![];
        for (i, (&ok, &ng)) in ok.iter().zip(ng.iter()).enumerate() {
            if ok + 1 < ng {
                let mid = (ok + ng) / 2;
                query.push((mid, i));
            }
        }
        if query.is_empty() {
            break;
        }
        query.sort();
        // 
        type T = (usize, usize, usize, usize);
        let merge = |a: &T, b: &T| -> T {
            let mut c = (a.0, b.1, a.2 + b.2, a.3.max(b.3));
            c.3.chmax(a.1 + b.0);
            if a.2 == a.0 {
                c.0 = a.2 + b.0;
            }
            if b.2 == b.0 {
                c.1 = b.2 + a.1;
            }
            c
        };
        let mut seg = segment_tree::PURQ::new(n, (0, 0, 0, 0), merge);
        for i in 0..n {
            seg.update_tmp(i, (0, 0, 1, 0));
        }
        seg.update_all();
        let mut x = n;
        for &(mid, i) in query.iter().rev() {
            while h.get(x - 1).map_or(false, |h| h.1 >= mid) {
                x -= 1;
                let k = h[x].0;
                seg.update(k, (1, 1, 1, 1));
            }
            let (l, r, w) = ask[i];
            if seg.find(l, r).3 >= w {
                ok[i] = mid;
            } else {
                ng[i] = mid;
            }
        }
    }
    for a in ok {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
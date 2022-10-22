use std::collections::*;
use std::io::Write;

type Set<T> = BTreeSet<T>;

// 
// x
// x
// y
// xy + (x - y + 1)/2) 
//

fn run() {
    input! {
        n: usize,
        a: [i32; n],
        m: usize,
        ask: [(usize1, usize); m],
    }
    let mut a = a;
    let inf = 10i32.pow(9) + 1;
    let mut ans = vec![inf; m];
    let mut query = vec![vec![]; n];
    for (i, &(l, r)) in ask.iter().enumerate() {
        query[l].push((r, i));
    }
    for _ in 0..2 {
        let mut ord = (0..n).map(|x| (a[x], x)).collect::<Vec<_>>();
        ord.sort_by_key(|p| (p.0, !p.1));
        let mut set = Set::new();
        let mut seg = SegmentTreePURQ::new(n, -inf, |a, b| std::cmp::max(*a, *b));
        let mut update = vec![vec![]; n];
        for (a, x) in ord {
            let update = &mut update[x];
            if let Some(&y) = set.range(x..).next() {
                let mut v = seg.find(y, y + 1);
                update.push((y as u32, a - v));
                let mut y = y;
                loop {
                    let key = (a + v) / 2 + 1;
                    y = seg.max_right(y + 1, |v| *v < key);
                    if y >= n {
                        break;
                    }
                    v = seg.find(y, y + 1);
                    update.push((y as u32, a - v));
                }
            }
            set.insert(x);
            seg.update(x, a);
        }
        let mut seg = SegmentTreePURQ::new(n, inf, |a, b| std::cmp::min(*a, *b));
        for (query, update) in query.iter().zip(update).rev() {
            for (x, v) in update {
                let x = x as usize;
                let v = v.min(seg.find(x, x + 1));
                seg.update(x, v);
            }
            for &(r, k) in query.iter() {
                ans[k] = ans[k].min(seg.find(0, r));
            }
        }
        a.iter_mut().for_each(|a| *a = inf - *a);
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin segment tree Point Update Range Query ----------
pub struct SegmentTreePURQ<T, F> {
    n: usize,
    size: usize,
    data: Vec<T>,
    e: T,
    op: F,
}

impl<T, F> SegmentTreePURQ<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    pub fn new(n: usize, e: T, op: F) -> Self {
        assert!(n > 0);
        let size = n.next_power_of_two();
        let data = vec![e.clone(); 2 * size];
        SegmentTreePURQ {
            n,
            size,
            data,
            e,
            op,
        }
    }
    pub fn update_tmp(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        self.data[x + self.size] = v;
    }
    pub fn update_all(&mut self) {
        for i in (1..self.size).rev() {
            self.data[i] = (self.op)(&self.data[2 * i], &self.data[2 * i + 1]);
        }
    }
    pub fn update(&mut self, x: usize, v: T) {
        assert!(x < self.n);
        let mut x = x + self.size;
        self.data[x] = v;
        x >>= 1;
        while x > 0 {
            self.data[x] = (self.op)(&self.data[2 * x], &self.data[2 * x + 1]);
            x >>= 1;
        }
    }
    pub fn find(&self, l: usize, r: usize) -> T {
        assert!(l <= r && r <= self.n);
        if l == r {
            return self.e.clone();
        }
        let mut l = self.size + l;
        let mut r = self.size + r;
        let mut x = self.e.clone();
        let mut y = self.e.clone();
        while l < r {
            if l & 1 == 1 {
                x = (self.op)(&x, &self.data[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = (self.op)(&self.data[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        (self.op)(&x, &y)
    }
    pub fn max_right<P>(&self, l: usize, f: P) -> usize
    where
        P: Fn(&T) -> bool,
    {
        assert!(l <= self.n);
        assert!(f(&self.e));
        if l == self.n {
            return self.n;
        }
        let mut l = l + self.size;
        let mut sum = self.e.clone();
        while {
            l >>= l.trailing_zeros();
            let v = (self.op)(&sum, &self.data[l]);
            if !f(&v) {
                while l < self.size {
                    l <<= 1;
                    let v = (self.op)(&sum, &self.data[l]);
                    if f(&v) {
                        sum = v;
                        l += 1;
                    }
                }
                return l - self.size;
            }
            sum = v;
            l += 1;
            l.count_ones() > 1
        } {}
        self.n
    }
}
// ---------- end segment tree Point Update Range Query ----------
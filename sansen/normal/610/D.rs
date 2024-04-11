// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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
        size: usize,
        data: Vec<T>,
        e: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T, F> PURQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> PURQ<T, F> {
            let size = size.next_power_of_two();
            PURQ {
                size,
                data: vec![e.clone(); 2 * size],
                e: e,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            let mut x = x + self.size;
            let data = &mut self.data;
            data[x] = v;
            x >>= 1;
            while x > 0 {
                data[x] = (self.op)(&data[2 * x], &data[2 * x + 1]);
                x >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            assert!(x < self.size);
            self.data[x + self.size] = v;
        }
        pub fn update_all(&mut self) {
            let data = &mut self.data;
            for k in (1..self.size).rev() {
                data[k] = (self.op)(&data[2 * k], &data[2 * k + 1]);
            }
        }
        pub fn find(&self, l: usize, r: usize) -> T {
            assert!(l <= r && r <= self.size);
            if l == r {
                return self.e.clone();
            }
            let mut p = self.e.clone();
            let mut q = self.e.clone();
            let mut l = l + self.size;
            let mut r = r + self.size;
            let data = &self.data;
            while l < r {
                if l & 1 == 1 {
                    p = (self.op)(&p, &data[l]);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    q = (self.op)(&data[r], &q);
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

fn run() {
    input! {
        n: usize,
        p: [(i64, i64, i64, i64); n],
    }
    let mut x = vec![];
    let mut y = vec![];
    for p in p.iter() {
        x.push(p.0);
        y.push(p.1);
        x.push(p.2);
        y.push(p.3);
    }
    y.sort();
    y.dedup();
    x.sort();
    x.dedup();
    let mut g = vec![vec![]; y.len()];
    let mut add = vec![vec![]; y.len()];
    let mut sub = vec![vec![]; y.len()];
    for (a, b, c, d) in p {
        let mut a = x.binary_search(&a).unwrap();
        let mut b = y.binary_search(&b).unwrap();
        let mut c = x.binary_search(&c).unwrap();
        let mut d = y.binary_search(&d).unwrap();
        if a > c {
            std::mem::swap(&mut a, &mut c);
        }
        if b > d {
            std::mem::swap(&mut b, &mut d);
        }
        if b == d {
            g[b].push((a, c));
        } else {
            add[b].push(a);
            sub[d].push(a);
        }
    }
    let mut cnt = vec![0; x.len()];
    let mut ans = 0i64;
    let mut seg = segment_tree::PURQ::new(x.len(), 0, |a, b| *a + *b);
    for (i, (g, (add, sub))) in g.iter_mut().zip(add.iter().zip(sub.iter())).enumerate() {
        g.sort();
        let mut line: Vec<(usize, usize)> = vec![];
        for &(l, r) in g.iter() {
            if line.last().map_or(false, |p| l <= p.1) {
                line.last_mut().unwrap().1.chmax(r);
            } else {
                line.push((l, r));
            }
        }
        for &x in add.iter() {
            cnt[x] += 1;
            if cnt[x] == 1 {
                seg.update(x, 1);
            }
        }
        ans += seg.find(0, x.len());
        for &(l, r) in line.iter() {
            ans += x[r] - x[l] + 1 - seg.find(l, r + 1);
        }
        for &x in sub.iter() {
            cnt[x] -= 1;
            if cnt[x] == 0 {
                seg.update(x, 0);
            }
        }
        if i + 1 < y.len() {
            ans += seg.find(0, x.len()) * (y[i + 1] - y[i] - 1);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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

// k

fn run() {
    input! {
        n: usize,
        k: usize,
        p: [(u64, u64, u64, u64); n],
    }
    let p = p.iter().map(|p| (p.0 + p.2, p.1 + p.3)).collect::<Vec<_>>();
    let mut x = p.iter().enumerate().map(|(k, p)| (p.0, k)).collect::<Vec<_>>();
    let mut y = p.iter().enumerate().map(|(k, p)| (p.1, k)).collect::<Vec<_>>();
    x.sort();
    y.sort();
    let inf = std::u64::MAX;
    let mut seg = segment_tree::PURQ::new(n, (inf, 0, inf, 0), |a, b| {
        (a.0.min(b.0), a.1.max(b.1), a.2.min(b.2), a.3.max(b.3))
    });
    for (i, p) in p.iter().enumerate() {
        seg.update_tmp(i, (p.0, p.0, p.1, p.1));
    }
    seg.update_all();
    use std::cell::RefCell;
    let seg = RefCell::new(seg);
    let cnt = RefCell::new(vec![0; n]);
    let del = RefCell::new(0);
    let sub = |x: usize| {
        let mut cnt = cnt.borrow_mut();
        cnt[x] += 1;
        if cnt[x] == 1 {
            *del.borrow_mut() += 1;
            seg.borrow_mut().update(x, (inf, 0, inf, 0));
        }
    };
    let add = |x: usize| {
        let mut cnt = cnt.borrow_mut();
        cnt[x] -= 1;
        if cnt[x] == 0 {
            *del.borrow_mut() -= 1;
            let (a, b) = p[x];
            seg.borrow_mut().update(x, (a, a, b, b));
        }
    };
    let find = || -> Option<(u64, u64, u64, u64)> {
        if *del.borrow() > k {
            None
        } else {
            Some(seg.borrow().find(0, n))
        }
    };
    let l = x[..k].iter();
    let r = x[(n - k)..].iter().rev();
    let d = y[..k].iter();
    let u = y[(n - k)..].iter().rev();
    let mut ans = std::u64::MAX;
    for a in 0..=k {
        l.clone().take(a).for_each(|a| sub(a.1));
        for b in 0..=k {
            r.clone().take(b).for_each(|a| sub(a.1));
            for c in 0..=k {
                d.clone().take(c).for_each(|a| sub(a.1));
                for d in 0..=k {
                    u.clone().take(d).for_each(|a| sub(a.1));
                    if let Some(p) = find() {
                        let mut w = (p.1 - p.0 + 1) / 2;
                        let mut h = (p.3 - p.2 + 1) / 2;
                        if w == 0 {
                            w += 1;
                        }
                        if h == 0 {
                            h += 1;
                        }
                        ans = ans.min(w * h);
                    }
                    u.clone().take(d).for_each(|a| add(a.1));
                }
                d.clone().take(c).for_each(|a| add(a.1));
            }
            r.clone().take(b).for_each(|a| add(a.1));
        }
        l.clone().take(a).for_each(|a| add(a.1));
    }
    println!("{}", ans);
}

fn main() {
    run();
}
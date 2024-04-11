// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
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
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
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

/*
fn naive() {
    input! {
        n: usize,
        p: u64,
        a: [u64; n],
    }
    let mut ans = vec![0; n];
    let mut q = std::collections::VecDeque::<(u64, usize)>::new();
    let mut active = std::collections::BinaryHeap::new();
    let mut seg = segment_tree::PURQ::new(n, false, |a, b| a || b);
    for t in 0..2000 {
        if !q.is_empty() && q.front().unwrap().0 == t {
            let (_, k) = q.pop_front().unwrap();
            seg.update(k, false);
        }
        for i in 0..n {
            if a[i] == t {
                active.push(n - i);
            }
        }
        if let Some(&v) = active.peek() {
            let k = n - v;
            if !seg.find(0, k + 1) {
                active.pop();
                let time = if q.is_empty() {
                    t + p
                } else {
                    let t = q.back().unwrap().0;
                    t + p
                };
                ans[k] = time;
                q.push_back((time, k));
                seg.update(k, true);
            }
        }
    }
}
*/

use std::cmp::min;

fn run() {
    input! {
        n: usize,
        p: u64,
        a: [u64; n],
    }
    let mut b = Vec::with_capacity(n);
    for i in 0..n {
        b.push((a[i], i));
    }
    b.sort();
    b.reverse();
    let mut ans = vec![0u64; n];
    let mut seg = segment_tree::PURQ::new(n, false, |a, b| a || b);
    let mut q = std::collections::VecDeque::<(u64, usize)>::new();
    let mut active = std::collections::BinaryHeap::new();
    let mut now = 0;
    while now < std::u64::MAX {
        if !q.is_empty() && q.front().unwrap().0 == now {
            let (_, k) = q.pop_front().unwrap();
            seg.update(k, false);
        }
        while let Some((v, k)) = b.pop() {
            if v > now {
                b.push((v, k));
                break;
            } else {
                active.push(n - k);
            }
        }
        if let Some(&v) = active.peek() {
            let k = n - v;
            if !seg.find(0, k + 1) {
                active.pop();
                seg.update(k, true);
                let time = if q.is_empty() {
                    now + p
                } else {
                    let t = q.back().unwrap().0;
                    t + p
                };
                ans[k] = time;
                q.push_back((time, k));
            }
        }
        let mut next = std::u64::MAX;
        if let Some(v) = q.front() {
            next = min(next, v.0);
        }
        if let Some(v) = b.last() {
            next = min(next, v.0);
        }
        now = next;
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
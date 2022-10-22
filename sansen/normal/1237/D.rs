// 
// 
//---------- begin SegmentTree Point update Range query ----------
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
//---------- end SegmentTree Point update Range query ----------
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
        a: [u32; n],
    }
    let mut p = vec![];
    for i in 0..n {
        p.push((a[i], i));
    }
    p.sort();
    let mut s = segment_tree::PURQ::new(2 * n, 0, std::cmp::max);
    for i in 0..n {
        s.update_tmp(i, a[i]);
        s.update_tmp(i + n, a[i]);
    }
    s.update_all();
    let mut ng = vec![];
    for i in 0..n {
        let (v, k) = p[i];
        if s.find(0, n) <= 2 * v {
            break;
        }
        let mut l = 0;
        let mut r = n + k + 1;
        while r - l > 1 {
            let m = (l + r) / 2;
            if s.find(m, n + k + 1) > 2 * v {
                l = m;
            } else {
                r = m;
            }
        }
        ng.push((l, n + k));
        ng.push((l + n, 2 * n + k));
        if l >= n {
            ng.push((l - n, k));
        }
    }
    ng.sort();
    let mut ans = vec![4 * n; n];
    let mut r = 8 * n;
    for i in (0..(3 * n)).rev() {
        while let Some((x, y)) = ng.pop() {
            if i <= x {
                r = std::cmp::min(y, r);
            } else {
                ng.push((x, y));
                break;
            }
        }
        ans[i % n] = std::cmp::min(ans[i % n], r - i);
    }
    let mut out = String::new();
    for i in 0..n {
        if ans[i] > 2 * n {
            out.push_str("-1 ");
        } else {
            out.push_str(&format!("{} ", ans[i]));
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
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

//

// O(N)
// 
// 2
// NY, NX 
// ?
// 
// x <= y ok
// x > y ?
// N
// 
// -> TLE
//
// 
// 10^6 log 

fn run() {
    input! {
        n: usize,
        x: u64,
        y: u64,
        a: [usize; n],
    }
    let m = 1_000_000;
    let mut p = vec![true; m + 1];
    p[0] = false;
    p[1] = false;
    for i in (2..).take_while(|p| p * p <= m) {
        if p[i] {
            for j in i..=(m / i) {
                p[i * j] = false;
            }
        }
    }
    type T = (u64, u64, u64);// 
    let merge = |a: T, b: T| -> T {
        (a.0 + b.0 + a.1 * b.2 * y, a.1 + b.1, a.2 + b.2)
    };
    let mut seg = segment_tree::PURQ::new(2 * m, (0, 0, 0), merge);
    let mut cnt = vec![0; m + 1];
    for a in a {
        cnt[a] += 1;
    }
    for i in 0..(2 * m) {
        seg.update_tmp(i, (0, 0, 1));
    }
    for (i, c) in cnt.iter().enumerate() {
        seg.update_tmp(i, (0, *c, 1));
    }
    seg.update_all();
    let mut ans = std::cmp::min(x, y) * n as u64;
    let k = (x / y) as usize;
    for (i, p) in p.iter().enumerate() {
        if !*p {
            continue;
        }
        let mut sum = 0;
        let mut l = 0;
        let mut r = i;
        while l < m && sum < ans {
            if x <= y {
                sum += x * seg.find(l + 1, r).1;
            } else if k + 1 > i {
                sum += seg.find(l + 1, r + 1).0;
            } else {
                sum += x * seg.find(l + 1, r - k).1;
                sum += seg.find(r - k, r + 1).0;
            }
            l = r;
            r = r + i;
        }
        ans = std::cmp::min(ans, sum);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
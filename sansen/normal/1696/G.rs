// 1
// b_1, ..., b_n
// 
//
// min {sum_{1 <= i < n} (p_i + q_i)}
// s.t.
//   xp_i + yq_i + yp_{i - 1} + xq_{i - 1} >= b_i (i > 0)
//   xp_1 + yq_1 >= b_1
//   p_i, q_i >= 0
//
// 
// max sum_i (b_i * r_i)
// s.t.
//   x * r_i + y * r_{i - 1} <= 1
//   y * r_i + x * r_{i - 1} <= 1
//
// 4

use std::io::Write;

fn run() {
    input! {
        n: usize,
        q: usize,
        x: i32,
        y: i32,
        b: [i32; n],
        ask: [(u8, usize1, usize); q],
    }
    type Mat = [[f64; 3]; 3];
    let inf = 1000000000f64;
    let mul = |a: &Mat, b: &Mat| -> Mat {
        let mut c = [[-inf; 3]; 3];
        for (c, a) in c.iter_mut().zip(a.iter()) {
            for (a, b) in a.iter().zip(b.iter()) {
                for (c, b) in c.iter_mut().zip(b.iter()) {
                    *c = (*a + *b).max(*c);
                }
            }
        }
        c
    };
    let (x, y) = (x.min(y), x.max(y));
    // 0
    // 1/y
    // 1/(x+y)
    //
    // 0: (0, 0)
    // 1: (0, 1/y)
    // 2: (1/y, 0)
    // 3: (1/(x+y), 1/(x+y))
    let gen = |b: i32| -> Mat {
        let b = b as f64;
        let mut mat = [[-inf; 3]; 3];
        mat[0][0] = 0f64;
        mat[0][1] = b / y as f64;
        mat[0][2] = b / (x + y) as f64;
        mat[1][0] = 0f64;
        mat[2][0] = 0f64;
        mat[2][2] = b / (x + y) as f64;
        mat
    };
    let mut zero = [[-inf; 3]; 3];
    for i in 0..3 {
        zero[i][i] = 0f64;
    }
    let mut seg = SegmentTreePURQ::new(n, zero, mul);
    for (i, b) in b.iter().enumerate() {
        seg.update_tmp(i, gen(*b));
    }
    seg.update_all();
    let mut b = b;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, l, r) in ask {
        if op == 2 {
            let mat = seg.find(l, r);
            let ans = *mat.iter().flatten().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
            writeln!(out, "{:.10}", ans).ok();
        } else {
            seg.update(l, gen(r as i32));
            b[l] = r as i32;
        }
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
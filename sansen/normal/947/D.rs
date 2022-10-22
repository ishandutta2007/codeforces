//---------- begin SegmentTree Point update Range query ----------
pub trait PURQ {
    type T: Clone;
    fn fold(l: &Self::T, r: &Self::T) -> Self::T;
    fn e() -> Self::T;
}

struct SegmentTreePURQ<R: PURQ> {
    seg: Vec<R::T>,
    size: usize,
}

#[allow(dead_code)]
impl<R: PURQ> SegmentTreePURQ<R> {
    fn new(n: usize) -> SegmentTreePURQ<R> {
        let size = n.next_power_of_two();
        SegmentTreePURQ {
            seg: vec![R::e(); 2 * size],
            size: size,
        }
    }
    fn build_by(a: &[R::T]) -> SegmentTreePURQ<R> {
        let size = a.len().next_power_of_two();
        let mut b = vec![R::e(); 2 * size];
        for i in 0..a.len() {
            b[i + size] = a[i].clone();
        }
        let mut seg = SegmentTreePURQ { seg: b, size: size };
        seg.update_all();
        seg
    }
    fn update(&mut self, x: usize, v: R::T) {
        assert!(x < self.size);
        let mut x = x + self.size;
        let a = &mut self.seg;
        a[x] = v;
        x >>= 1;
        while x > 0 {
            a[x] = R::fold(&a[2 * x], &a[2 * x + 1]);
            x >>= 1;
        }
    }
    fn update_tmp(&mut self, x: usize, v: R::T) {
        self.seg[self.size + x] = v;
    }
    fn update_all(&mut self) {
        let a = &mut self.seg;
        for i in (1..self.size).rev() {
            a[i] = R::fold(&a[2 * i], &a[2 * i + 1]);
        }
    }
    fn find(&self, l: usize, r: usize) -> R::T {
        assert!(l <= r && r <= self.size);
        let mut x = R::e();
        let mut y = R::e();
        let mut l = l + self.size;
        let mut r = r + self.size;
        let a = &self.seg;
        while l < r {
            if l & 1 == 1 {
                x = R::fold(&x, &a[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                y = R::fold(&a[r], &y);
            }
            l >>= 1;
            r >>= 1;
        }
        R::fold(&x, &y)
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

// C -> AB -> AAC -> AAAB -> B
// C -> B 
//
// A -> BB
// B -> AB
// AAA -> empty
//
// Amod 3?
// 
//
// B -> AB -> AAB -> AAAB -> B
// 
// B...BA..A 
// BTmod2A
// AB
// /2B
// AAA -> empty 
//
// WA
//
// B
//
// WA
//
//
//

struct R;
impl PURQ for R {
    // B...BA...A
    // BA
    type T = (usize, usize);
    fn fold(l: &Self::T, r: &Self::T) -> Self::T {
        if r.0 == 0 {
            (l.0, l.1 + r.1)
        } else {
            (l.0 + r.0, r.1)
        }
    }
    fn e() -> Self::T {
        (0, 0)
    }
}

fn run() {
    input! {
        s: bytes,
        t: bytes,
        q: usize,
        ask: [(usize1, usize, usize1, usize); q],
    }
    let mut seg_s = SegmentTreePURQ::<R>::new(s.len());
    for (i, s) in s.iter().enumerate() {
        if *s == b'A' {
            seg_s.update_tmp(i, (0, 1));
        } else {
            seg_s.update_tmp(i, (1, 0));
        }
    }
    seg_s.update_all();
    let mut seg_t = SegmentTreePURQ::<R>::new(t.len());
    for (i, s) in t.iter().enumerate() {
        if *s == b'A' {
            seg_t.update_tmp(i, (0, 1));
        } else {
            seg_t.update_tmp(i, (1, 0));
        }
    }
    seg_t.update_all();
    let mut out = String::new();
    for (a, b, c, d) in ask {
        let ans = || -> bool {
            let (x, y) = seg_s.find(a, b);
            let (z, w) = seg_t.find(c, d);
            let mut ans = false;
            if x == 0 {
                if z > 0 {
                    ans |= y > w && z % 2 == 0;
                } else {
                    ans |= y >= w && (y - w) % 3 == 0;
                }
                return ans;
            }
            if z >= x && (z - x) % 2 == 0 && y >= w {
                let d = (z - x) / 2;
                let mut ok = false;
                ok |= (y - w) % 3 == 0;
                ok |= d > 0 && y > w;
                ans |= ok;
            }
            ans
        }();
        if ans {
            out.push('1');
        } else {
            out.push('0');
        }
    }
    println!("{}", out);
}

fn main() {
    run();
}
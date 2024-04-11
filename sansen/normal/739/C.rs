// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        if *self > x {
            *self = x;
            true
        } else {
            false
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        if *self < x {
            *self = x;
            true
        } else {
            false
        }
    }
}
// ---------- end chmin, chmax ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(&T, &T) -> T> {
        size: usize,
        a: Vec<Option<T>>,
        fold: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(&T, &T) -> T> PURQ<T, F> {
        pub fn new(len: usize, fold: F) -> PURQ<T, F> {
            let size = len.next_power_of_two();
            PURQ {
                size: size,
                a: vec![None; 2 * size],
                fold: fold,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.size + x;
            self.a[k] = Some(v);
            k >>= 1;
            while k > 0 {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
                k >>= 1;
            }
        }
        fn merge(&self, a: &Option<T>, b: &Option<T>) -> Option<T> {
            match (a.as_ref(), b.as_ref()) {
                (Some(a), Some(b)) => Some((self.fold)(a, b)),
                (Some(a), None) => Some(a.clone()),
                (None, Some(b)) => Some(b.clone()),
                (None, None) => None,
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.size] = Some(v);
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.size)).rev() {
                self.a[k] = self.merge(&self.a[2 * k], &self.a[2 * k + 1]);
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p: Option<T> = None;
            let mut q: Option<T> = None;
            let a = &self.a;
            l += self.size;
            r += self.size;
            while l < r {
                if (l & 1) == 1 {
                    p = self.merge(&p, &a[l]);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = self.merge(&a[r], &q);
                }
                l >>= 1;
                r >>= 1;
            }
            self.merge(&p, &q).unwrap()
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

use std::cmp::*;

//  ---+++
// 
// 
// ---+++++++++++---()---- 
// 

use std::io::Write;

#[derive(Clone, Default)]
struct Node {
    left_sign: i8,
    right_sign: i8,
    left_minus_plus: usize,
    left_plus: usize,
    right_plus_minus: usize,
    right_minus: usize,
    max: usize,
    len: usize,
}

fn fold(l: &Node, r: &Node) -> Node {
    let mut ans: Node = std::default::Default::default();
    ans.left_sign = l.left_sign;
    ans.right_sign = r.right_sign;
    ans.len = l.len + r.len;
    ans.max.chmax(l.max);
    ans.max.chmax(r.max);
    ans.max.chmax(l.right_plus_minus + r.left_plus);
    ans.max.chmax(l.right_minus + r.left_minus_plus);
    ans.left_plus = l.left_plus;
    if l.left_plus == l.len {
        ans.left_plus += r.left_plus;
    }
    ans.left_minus_plus = l.left_minus_plus;
    if l.left_minus_plus == l.len {
        if l.right_sign == -1 {
            ans.left_minus_plus += r.left_minus_plus;
        } else {
            ans.left_minus_plus += r.left_plus;
        }
    }
    ans.right_minus = r.right_minus;
    if r.right_minus == r.len {
        ans.right_minus += l.right_minus;
    }
    ans.right_plus_minus = r.right_plus_minus;
    if r.right_plus_minus == r.len {
        if r.left_sign == 1 {
            ans.right_plus_minus += l.right_plus_minus;
        } else {
            ans.right_plus_minus += l.right_minus;
        }
    }
    ans
}

fn single(val: i64) -> Node {
    let mut node: Node = std::default::Default::default();
    node.len = 1;
    if val > 0 {
        node.left_sign = 1;
        node.right_sign = 1;
        node.left_minus_plus = 1;
        node.left_plus = 1;
        node.right_plus_minus = 1;
        node.max = 1;
    } else if val < 0 {
        node.left_sign = -1;
        node.right_sign = -1;
        node.left_minus_plus = 1;
        node.right_plus_minus = 1;
        node.right_minus = 1;
        node.max = 1;
    }
    node
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [i64; n],
        m: usize,
        ask: [(usize1, usize, i64); m],
    }
    let mut b = vec![0];
    for a in a.windows(2) {
        let op = a[0] - a[1];
        b.push(op);
    }
    b.push(0);
    b.push(0);
    let mut seg = segment_tree::PURQ::new(b.len(), fold);
    for (i, b) in b.iter().enumerate() {
        seg.update_tmp(i, single(*b));
    }
    seg.update_all();
    for (l, r, d) in ask {
        b[l] -= d;
        seg.update(l, single(b[l]));
        b[r] += d;
        seg.update(r, single(b[r]));
        let mut ans = 1;
        if n > 1 {
            ans.chmax(seg.find(1, n).max + 1);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
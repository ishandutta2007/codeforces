// ---------- begin Aho-Corasick ----------
const F: usize = 26;

fn convert(s: Vec<char>) -> Vec<usize> {
    let mut a = Vec::with_capacity(s.len());
    for c in s {
        let k = c.to_digit(36).unwrap() as usize - 10;
        a.push(k);
    }
    a
}

struct ACTrieNode {
    elem: bool,
    fail: usize,
    depth: usize,
    next: [usize; F],
}

impl ACTrieNode {
    fn new() -> ACTrieNode {
        ACTrieNode {
            elem: false,
            fail: 0,
            depth: 0,
            next: [0; F],
        }
    }
}

struct AhoCorasick {
    node: Vec<ACTrieNode>,
}

#[allow(dead_code)]
impl AhoCorasick {
    fn new() -> Self {
        let root = ACTrieNode::new();
        AhoCorasick {
            node: vec![root],
        }
    }
    fn insert(&mut self, s: &Vec<usize>) -> usize {
        let node = &mut self.node;
        let mut v = 0;
        for &k in s {
            if node[v].next[k] == 0 {
                node[v].next[k] = node.len();
                let mut t = ACTrieNode::new();
                t.depth = node[v].depth + 1;
                node.push(t);
            }
            v = node[v].next[k];
        }
        node[v].elem = true;
        v
    }
    fn build(&mut self) {
        let mut q = std::collections::VecDeque::new();
        let node = &mut self.node;
        for i in 0..F {
            if node[0].next[i] != 0 {
                q.push_back(node[0].next[i]);
            }
        }
        while let Some(v) = q.pop_front() {
            for i in 0..F {
                let u = node[v].next[i];
                if u == 0 {
                    continue;
                }
                let mut fail = node[v].fail;
                while fail > 0 && node[fail].next[i] == 0 {
                    fail = node[fail].fail;
                }
                let f = node[fail].next[i];
                node[u].fail = f;
                q.push_back(u);
            }
        }
    }
    fn next(&self, v: usize, k: usize) -> usize {
        self.node[v].next[k]
    }
    fn trans(&self, mut v: usize, k: usize) -> usize {
        let node = &self.node;
        while v > 0 && node[v].next[k] == 0 {
            v = node[v].fail;
        }
        node[v].next[k]
    }
    fn elem(&self, k: usize) -> bool {
        self.node[k].elem
    }
    fn fail(&self, k: usize) -> usize {
        self.node[k].fail
    }
    fn depth(&self, k: usize) -> usize {
        self.node[k].depth
    }
    fn get_size(&self) -> usize {
        self.node.len()
    }
}
// ---------- end Aho-Corasick ----------
// ---------- begin Matrix ----------
#[allow(dead_code)]
mod matrix {
    use std::ops::{Add, Mul};
    pub trait SemiRing: Add<Output = Self> + Mul<Output = Self> + Copy {
        fn zero() -> Self;
        fn one() -> Self;
    }
    pub const SIZE: usize = 201;
    #[derive(Clone)]
    pub struct SquareMatrix<T: SemiRing> {
        buf: [[T; SIZE]; SIZE],
    }
    impl<T: SemiRing> SquareMatrix<T> {
        pub fn zero() -> Self {
            let z = T::zero();
            SquareMatrix {
                buf: [[z; SIZE]; SIZE],
            }
        }
        pub fn identity() -> Self {
            let mut m = Self::zero();
            for i in 0..SIZE {
                m.buf[i][i] = T::one();
            }
            m
        }
        pub fn set_at(&mut self, i: usize, j: usize, v: T) {
            self.buf[i][j] = v;
        }
        pub fn get_at(&self, i: usize, j: usize) -> T {
            self.buf[i][j]
        }
        pub fn matmul(&self, rhs: &Self) -> Self {
            let mut res = Self::zero();
            for (x, a) in res.buf.iter_mut().zip(self.buf.iter()) {
                for (a, b) in a.iter().zip(rhs.buf.iter()) {
                    for (x, b) in x.iter_mut().zip(b.iter()) {
                        *x = *x + *a * *b;
                    }
                }
            }
            res
        }
        pub fn matadd(&self, rhs: &Self) -> Self {
            let mut c = Self::zero();
            for (c, (a, b)) in c.buf.iter_mut().zip(self.buf.iter().zip(rhs.buf.iter())) {
                for (c, (a, b)) in c.iter_mut().zip(a.iter().zip(b.iter())) {
                    *c = *a + *b;
                }
            }
            c
        }
        pub fn matpow(&self, mut n: u64) -> Self {
            let mut t = Self::identity();
            let mut s = self.clone();
            while n > 0 {
                if n & 1 == 1 {
                    t = t.matmul(&s);
                }
                s = s.matmul(&s);
                n >>= 1;
            }
            t
        }
    }
}
// ---------- end Matrix ----------
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

use std::io::Write;
use matrix::*;
use std::ops::*;

#[derive(Clone, Copy, Eq, PartialEq, Ord, PartialOrd)]
struct Value(i64);

impl Add for Value {
    type Output = Self;
    fn add(self, rhs: Self) -> Self::Output {
        std::cmp::max(self, rhs)
    }
}

impl Mul for Value {
    type Output = Self;
    fn mul(self, rhs: Self) -> Self::Output {
        Value(self.0 + rhs.0) + Value::zero()
    }
}

impl SemiRing for Value {
    fn zero() -> Self {
        Value(-10i64.pow(17))
    }
    fn one() -> Self {
        Value(0)
    }
}

type Matrix = SquareMatrix<Value>;

fn run() {
    input! {
        n: usize,
        l: u64,
        a: [i64; n],
        s: [chars; n],
    }
    let mut aho = AhoCorasick::new();
    let mut index = vec![SIZE; n];
    for (index, s) in index.iter_mut().zip(s.iter()) {
        let s = convert(s.clone());
        *index = aho.insert(&s);
    }
    aho.build();
    assert!(aho.get_size() <= SIZE);
    let mut mat = Matrix::zero();
    for i in 0..aho.get_size() {
        for k in 0..F {
            let v = aho.trans(i, k);
            mat.set_at(i, v, Value::one());
        }
    }
    let mut sum = vec![0; aho.get_size()];
    for (a, k) in a.iter().zip(index.iter()) {
        sum[*k] += *a;
    }
    let mut q = std::collections::VecDeque::new();
    q.push_back(0);
    while let Some(v) = q.pop_front() {
        let f = aho.fail(v);
        sum[v] += sum[f];
        for j in 0..aho.get_size() {
            let x = mat.get_at(j, v).0;
            mat.set_at(j, v, Value(x + sum[v]));
        }
        for k in 0..F {
            let u = aho.next(v, k);
            if u > 0 {
                q.push_back(u);
            }
        }
    }
    let mat = mat.matpow(l);
    let mut ans = Value::zero();
    for i in 0..aho.get_size() {
        ans = ans + mat.get_at(0, i);
    }
    println!("{}", ans.0);
}

fn main() {
    run();
}
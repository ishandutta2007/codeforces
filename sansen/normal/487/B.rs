// ---------- begin Foldable Deque ----------
struct FoldableDeque<T, F> {
    front: Vec<(T, T)>,
    back: Vec<(T, T)>,
    op: F,
}

#[allow(dead_code)]
impl<T, F> FoldableDeque<T, F>
where
    T: Clone,
    F: Fn(&T, &T) -> T,
{
    fn new(op: F) -> Self {
        FoldableDeque {
            front: Vec::new(),
            back: Vec::new(),
            op: op,
        }
    }
    fn find(&self) -> Option<T> {
        match (self.front.last(), self.back.last()) {
            (Some(a), Some(b)) => Some((self.op)(&a.1, &b.1)),
            (Some(a), None) => Some(a.1.clone()),
            (None, Some(b)) => Some(b.1.clone()),
            (None, None) => None,
        }
    }
    fn clear(&mut self) {
        self.front.clear();
        self.back.clear();
    }
    fn len(&self) -> usize {
        self.front.len() + self.back.len()
    }
    fn push_back(&mut self, val: T) {
        let sum = self
            .back
            .last()
            .map_or_else(|| val.clone(), |p| (self.op)(&p.1, &val));
        self.back.push((val, sum));
    }
    fn push_front(&mut self, val: T) {
        let sum = self
            .front
            .last()
            .map_or_else(|| val.clone(), |p| (self.op)(&val, &p.1));
        self.front.push((val, sum));
    }
    fn pop_front(&mut self) -> Option<T> {
        if self.front.is_empty() {
            let a = self.back.clone();
            let m = (self.back.len() + 1) / 2;
            self.back.clear();
            let (f, b) = a.split_at(m);
            for v in f.iter().rev() {
                self.push_front(v.0.clone());
            }
            for v in b.iter() {
                self.push_back(v.0.clone());
            }
        }
        self.front.pop().map(|p| p.0)
    }
    fn pop_back(&mut self) -> Option<T> {
        if self.back.is_empty() {
            let a = self.front.clone();
            let m = (self.front.len() + 1) / 2;
            self.front.clear();
            let (f, b) = a.split_at(m);
            for v in b.iter() {
                self.push_front(v.0.clone());
            }
            for v in f.iter().rev() {
                self.push_back(v.0.clone());
            }
        }
        self.back.pop().map(|p| p.0)
    }
    fn front(&self) -> Option<&T> {
        self.front
            .last()
            .map_or_else(|| self.back.get(0).map(|p| &p.0), |p| Some(&p.0))
    }
    fn back(&self) -> Option<&T> {
        self.back
            .last()
            .map_or_else(|| self.front.get(0).map(|p| &p.0), |p| Some(&p.0))
    }
}
// ---------- end Foldable Deque ----------
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

use std::cmp::*;

fn run() {
    input! {
        n: usize,
        s: i64,
        l: usize,
        a: [i64; n],
    }
    let mut a = a;
    a.push(std::i64::MAX / 100);
    type T = (i64, i64);
    let mut deq = FoldableDeque::new(|a: &T, b: &T| (min(a.0, b.0), max(a.1, b.1)));
    let mut trans = vec![(0, 0); n + 1];
    let mut r = 0;
    for i in 0..n {
        while r < a.len() && deq.find().map_or(true, |(a, b)| b - a <= s) {
            deq.push_back((a[r], a[r]));
            r += 1;
        }
        r -= 1;
        deq.pop_back();
        if deq.len() >= l {
            trans[i] = (i + l, r);
        }
        deq.pop_front();
    }
    let mut dp = vec![n; n + 1];
    dp[0] = 0;
    let mut set = (0..=n).collect::<std::collections::BTreeSet<_>>();
    let mut q = std::collections::VecDeque::new();
    q.push_back(0);
    while let Some(v) = q.pop_front() {
        let (l, r) = trans[v];
        if r == 0 {
            continue;
        }
        let d = set.range(l..=r).cloned().collect::<Vec<_>>();
        for d in d {
            set.remove(&d);
            dp[d] = dp[v] + 1;
            q.push_back(d);
        }
    }
    if set.contains(&n) {
        println!("-1");
    } else {
        println!("{}", dp[n]);
    }
}

fn main() {
    run();
}
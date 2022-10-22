// ---------- begin super slice ----------
pub trait SuperSlice {
    type Item;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn lower_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn lower_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        Self::Item: Ord;
    fn upper_bound_by<F>(&self, f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering;
    fn upper_bound_by_key<K, F>(&self, key: &K, f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K;
}

impl<T> SuperSlice for [T] {
    type Item = T;
    fn lower_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.lower_bound_by(|p| p.cmp(key))
    }
    fn lower_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Greater))
            .unwrap_err()
    }
    fn lower_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.lower_bound_by(|p| f(p).cmp(key))
    }
    fn upper_bound(&self, key: &Self::Item) -> usize
    where
        T: Ord,
    {
        self.upper_bound_by(|p| p.cmp(key))
    }
    fn upper_bound_by<F>(&self, mut f: F) -> usize
    where
        F: FnMut(&Self::Item) -> std::cmp::Ordering,
    {
        self.binary_search_by(|p| f(p).then(std::cmp::Ordering::Less))
            .unwrap_err()
    }
    fn upper_bound_by_key<K, F>(&self, key: &K, mut f: F) -> usize
    where
        K: Ord,
        F: FnMut(&Self::Item) -> K,
    {
        self.upper_bound_by(|p| f(p).cmp(key))
    }
}
// ---------- end super slice ----------

mod persistent_segment_tree {
    use std::rc::*;
    pub trait BinaryOperation {
        type T: Clone;
        fn fold(l: Self::T, r: Self::T) -> Self::T;
        fn e() -> Self::T;
    }
    struct Node<R: BinaryOperation> {
        val: R::T,
        left: Tree<R>,
        right: Tree<R>,
    }

    struct Tree<R: BinaryOperation>(Option<Rc<Node<R>>>);

    impl<R: BinaryOperation> Default for Tree<R> {
        fn default() -> Self {
            Tree(None)
        }
    }

    impl<R: BinaryOperation> Clone for Tree<R> {
        fn clone(&self) -> Self {
            Tree(self.0.as_ref().map(|node| node.clone()))
        }
    }

    impl<R: BinaryOperation> Node<R> {
        fn new_node(left: Tree<R>, right: Tree<R>) -> Self {
            Node {
                val: R::fold(left.get_val(), right.get_val()),
                left: left,
                right: right,
            }
        }
        fn single(val: R::T) -> Self {
            Node {
                val,
                left: Tree::default(),
                right: Tree::default(),
            }
        }
    }

    impl<R: BinaryOperation> Tree<R> {
        fn from_node(node: Node<R>) -> Self {
            Tree(Some(Rc::new(node)))
        }
        fn get_val(&self) -> R::T {
            self.0.as_ref().map_or_else(R::e, |node| node.val.clone())
        }
        fn find(&self, l: usize, r: usize, x: usize, y: usize) -> R::T {
            if self.0.is_none() || y <= l || r <= x {
                return R::e();
            }
            let node = self.0.as_ref().unwrap();
            if x <= l && r <= y {
                node.val.clone()
            } else {
                let m = (l + r) / 2;
                R::fold(node.left.find(l, m, x, y), node.right.find(m, r, x, y))
            }
        }
        fn update(&self, l: usize, r: usize, x: usize, val: R::T) -> Self {
            if l + 1 == r {
                return Self::from_node(Node::single(val));
            }
            let mut left = Tree::default();
            let mut right = Tree::default();
            if let Some(node) = self.0.as_ref() {
                left = node.left.clone();
                right = node.right.clone();
            }
            let m = (l + r) / 2;
            if x < m {
                left = left.update(l, m, x, val);
            } else {
                right = right.update(m, r, x, val);
            }
            Self::from_node(Node::new_node(left, right))
        }
        fn max_right<F>(&self, l: usize, r: usize, x: usize, v: &mut R::T, f: &F) -> Option<usize>
        where
            F: Fn(&R::T) -> bool,
        {
            if r <= x {
                return None;
            }
            if x <= l {
                let s = R::fold(v.clone(), self.get_val());
                if f(&s) {
                    *v = s;
                    return None;
                }
            }
            if x <= l && l + 1 == r {
                return Some(l);
            }
            let node = self.0.as_ref().unwrap();
            let mid = (l + r) / 2;
            let res = node.left.max_right(l, mid, x, v, f);
            if res.is_some() {
                return res;
            }
            node.right.max_right(mid, r, x, v, f)
        }
    }

    #[derive(Clone)]
    pub struct PURQ<R: BinaryOperation> {
        root: Tree<R>,
        left: usize,
        right: usize,
    }

    impl<R: BinaryOperation> PURQ<R> {
        pub fn new(left: usize, right: usize) -> Self {
            PURQ {
                root: Tree::default(),
                left: left,
                right: right,
            }
        }
        pub fn update(&self, x: usize, val: R::T) -> Self {
            assert!(self.left <= x && x < self.right);
            PURQ {
                root: self.root.update(self.left, self.right, x, val),
                left: self.left,
                right: self.right,
            }
        }
        pub fn find(&self, l: usize, r: usize) -> R::T {
            assert!(self.left <= l && l < r && r <= self.right);
            self.root.find(self.left, self.right, l, r)
        }
        pub fn max_right<F>(&self, l: usize, f: F) -> (usize, R::T)
        where
            F: Fn(&R::T) -> bool,
        {
            assert!(f(&R::e()) && self.left <= l && l <= self.right);
            if l == self.right {
                return (l, R::e());
            }
            let mut val = R::e();
            let pos = self.root.max_right(self.left, self.right, l, &mut val, &f).unwrap_or(self.right);
            (pos, val)
        }
    }
}

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

use persistent_segment_tree::*;

struct R;
impl BinaryOperation for R {
    type T = (i64, i64);
    fn fold(l: Self::T, r: Self::T) -> Self::T {
        (l.0 + r.0, l.1 + r.1)
    }
    fn e() -> Self::T {
        (0, 0)
    }
}

fn run() {
    /*
    let n = 200000;
    let p = (0..n)
        .map(|_| {
            let mut r = rand() % 1000000000 + 1;
            let mut c = rand() % 1000000000 + 1;
            if r > c {
                std::mem::swap(&mut r, &mut c);
            }
            (r as i64, c as i64)
        })
        .collect::<Vec<_>>();
    */
    input! {
        n: usize,
        p: [(i64, i64); n],
        q: usize,
        ask: [(i64, i64); q],
    }
    let mut time = p
        .iter()
        .enumerate()
        .map(|(k, &(c, r))| ((c + r - 1) / r, k))
        .collect::<Vec<_>>();
    time.push((0, n));
    time.sort_by_key(|p| p.0);
    let mut seg = PURQ::<R>::new(0, n);
    for i in 0..n {
        seg = seg.update(i, (0, p[i].1));
    }
    let mut memo = vec![seg];
    for i in 1..time.len() {
        let (_, k) = time[i];
        let (c, _) = p[k];
        let seg = memo[i - 1].update(k, (c, 0));
        memo.push(seg);
    }
    // (1)
    let mut stack = (0..n)
        .map(|k| {
            let (c, _) = p[k];
            (k, k + 1, 0, c)
        })
        .rev()
        .collect::<Vec<_>>();
    let mut ans = 0;
    for (t, mut h) in ask {
        while h > 0 && !stack.is_empty() {
            let (l, r, last, c) = stack.pop().unwrap();
            if l + 1 == r {
                let c = (c + (t - last) * p[l].1).min(p[l].0);
                let v = h.min(c);
                h -= v;
                if c > v {
                    stack.push((l, l + 1, t, c - v));
                }
                continue;
            }
            let pos = time.upper_bound_by_key(&(t - last), |p| p.0) - 1;
            let (s, w) = memo[pos].find(l, r);
            let c = s + w * (t - last);
            if c <= h {
                h -= c;
                continue;
            }
            let (x, (s, w)) = memo[pos].max_right(l, |&(s, w)| s + w * (t - last) <= h);
            h -= s + w * (t - last);
            if x + 1 < r {
                stack.push((x + 1, r, last, 0));
            }
            let p = p[x];
            let c = p.0.min(p.1 * (t - last));
            stack.push((x, x + 1, t, c - h));
            h = 0;
        }
        ans += h;
        let r = stack.last().map_or(n, |p| p.0);
        if r > 0 {
            stack.push((0, r, t, 0));
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
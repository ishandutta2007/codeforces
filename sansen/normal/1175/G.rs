// ---------- begin persistent li-chao tree ----------
mod persistent_lichao {
    use std::rc::*;

    #[derive(Clone, Debug)]
    struct Line(i64, i64);

    impl Line {
        fn eval(&self, x: i64) -> i64 {
            self.0 * x + self.1
        }
    }

    #[derive(Default, Clone)]
    struct Tree(Option<Rc<Node>>);

    #[derive(Clone)]
    struct Node {
        line: Line,
        left: Tree,
        right: Tree,
    }

    impl Tree {
        fn new(line: Line, left: Tree, right: Tree) -> Self {
            Tree(Some(Rc::new(Node { line, left, right })))
        }
        fn find(&self, l: i64, r: i64, x: i64) -> i64 {
            if self.0.is_none() {
                return std::i64::MAX;
            }
            let node = self.0.as_ref().unwrap();
            let mut ans = node.line.eval(x);
            let mid = (l + r) / 2;
            if x < mid {
                ans = ans.min(node.left.find(l, mid - 1, x));
            }
            if mid < x {
                ans = ans.min(node.right.find(mid + 1, r, x));
            }
            ans
        }
        fn insert(&self, l: i64, r: i64, mut line: Line) -> Self {
            if l > r {
                return Self::default();
            }
            if self.0.is_none() {
                return Tree::new(line, Self::default(), Self::default());
            }
            let node = self.0.as_ref().unwrap();
            let mut p = node.line.clone();
            if p.eval(l) <= line.eval(l) && p.eval(r) <= line.eval(r) {
                return self.clone();
            }
            let mid = (l + r) / 2;
            if p.eval(mid) > line.eval(mid) {
                std::mem::swap(&mut p, &mut line);
            }
            let mut left = node.left.clone();
            let mut right = node.right.clone();
            if p.eval(l) > line.eval(l) {
                left = left.insert(l, mid - 1, line);
            } else if p.eval(r) > line.eval(r) {
                right = right.insert(mid + 1, r, line);
            }
            Tree::new(p, left, right)
        }
    }

    #[derive(Clone)]
    pub struct LiChaoTree {
        left: i64,
        right: i64,
        root: Tree,
    }

    impl LiChaoTree {
        pub fn new(left: i64, right: i64) -> Self {
            assert!(left <= right);
            LiChaoTree {
                left,
                right,
                root: Tree::default(),
            }
        }
        pub fn add_line(&self, a: i64, b: i64) -> Self {
            LiChaoTree {
                left: self.left,
                right: self.right,
                root: self.root.insert(self.left, self.right, Line(a, b)),
            }
        }
        pub fn find(&self, x: i64) -> i64 {
            assert!(self.left <= x && x <= self.right);
            self.root.find(self.left, self.right, x)
        }
    }
}
// ---------- end persistent li-chao tree ----------
// ---------- begin li-chao tree ----------
mod lichao {

    #[derive(Clone, Debug)]
    struct Line(i64, i64);

    impl Line {
        fn eval(&self, x: i64) -> i64 {
            self.0 * x + self.1
        }
    }

    #[derive(Default, Clone)]
    struct Tree(Option<Box<Node>>);

    #[derive(Clone)]
    struct Node {
        line: Line,
        left: Tree,
        right: Tree,
    }

    impl Tree {
        fn find(&self, l: i64, r: i64, x: i64) -> i64 {
            if self.0.is_none() {
                return std::i64::MAX;
            }
            let node = self.0.as_ref().unwrap();
            let mut ans = node.line.eval(x);
            let mid = (l + r) / 2;
            if x < mid {
                ans = ans.min(node.left.find(l, mid - 1, x));
            }
            if mid < x {
                ans = ans.min(node.right.find(mid + 1, r, x));
            }
            ans
        }
        fn insert(&mut self, l: i64, r: i64, mut line: Line) {
            if l > r {
                return;
            }
            if self.0.is_none() {
                self.0 = Some(Box::new(Node {
                    line: line,
                    left: Tree::default(),
                    right: Tree::default(),
                }));
                return;
            }
            let node = self.0.as_mut().unwrap();
            let mid = (l + r) / 2;
            if node.line.eval(mid) > line.eval(mid) {
                std::mem::swap(&mut node.line, &mut line);
            }
            if node.line.eval(l) > line.eval(l) {
                node.left.insert(l, mid - 1, line);
            } else if node.line.eval(r) > line.eval(r) {
                node.right.insert(mid + 1, r, line);
            }
        }
        fn merge(&mut self, rhs: Self, l: i64, r: i64) {
            if l > r {
                return;
            }
            if self.0.is_none() {
                self.0 = rhs.0;
                return;
            }
            if rhs.0.is_none() {
                return;
            }
            let node = self.0.as_mut().unwrap();
            let Node {
                mut line,
                left,
                right,
            } = *rhs.0.unwrap();
            let mid = (l + r) / 2;
            if node.line.eval(mid) > line.eval(mid) {
                std::mem::swap(&mut node.line, &mut line);
            }
            node.left.merge(left, l, mid - 1);
            node.right.merge(right, mid + 1, r);
            if node.line.eval(l) > line.eval(l) {
                node.left.insert(l, mid - 1, line);
            } else if node.line.eval(r) > line.eval(r) {
                node.right.insert(mid + 1, r, line);
            }
        }
    }

    pub struct LiChaoTree {
        left: i64,
        right: i64,
        root: Tree,
    }

    impl LiChaoTree {
        pub fn new(left: i64, right: i64) -> Self {
            assert!(left <= right);
            LiChaoTree {
                left,
                right,
                root: Tree::default(),
            }
        }
        pub fn add_line(&mut self, a: i64, b: i64) {
            self.root.insert(self.left, self.right, Line(a, b));
        }
        pub fn find(&self, x: i64) -> i64 {
            assert!(self.left <= x && x <= self.right);
            self.root.find(self.left, self.right, x)
        }
        pub fn merge(&mut self, rhs: Self) {
            assert!(self.left == rhs.left && self.right == rhs.right);
            self.root.merge(rhs.root, self.left, self.right);
        }
    }
}
// ---------- end li-chao tree ----------
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

type CHT = lichao::LiChaoTree;
type CHT2 = persistent_lichao::LiChaoTree;

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [i64; n],
    }
    let left = -20000;
    let right = 20000;
    let inf = 10i64.pow(9);
    let mut dp = vec![inf; n + 1];
    dp[n] = 0;
    for _ in 0..k {
        let mut next = vec![inf; dp.len() - 1];
        let mut stack: Vec<(i64, CHT, CHT2)> = vec![];
        for (l, (next, &a)) in next.iter_mut().zip(&a).enumerate().rev() {
            let l = l as i64;
            let mut cht = CHT::new(left, right);
            cht.add_line(l + 1, dp[l as usize + 1]);
            while stack.last().map_or(false, |p| p.0 <= a) {
                cht.merge(stack.pop().unwrap().1);
            }
            let mut tree = stack.last().map_or(CHT2::new(left, right), |p| p.2.clone());
            tree = tree.add_line(a, cht.find(a));
            *next = tree.find(-l);
            stack.push((a, cht, tree));
        }
        dp = next;
    }
    println!("{}", dp[0]);
}

fn main() {
    run();
}
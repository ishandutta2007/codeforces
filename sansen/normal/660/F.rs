mod lichao {
    use std;
    use std::cmp::Ordering;
    type T = i64;
    const INF: T = std::i64::MIN;
    fn get_mid(l: T, r: T) -> T {
        (l + r) / 2
    }
    fn compare(l: T, r: T) -> Ordering {
        l.cmp(&r).reverse()
    }
    #[derive(Clone, Copy)]
    pub struct Line(T, T);
    impl Line {
        fn eval(&self, x: T) -> T {
            self.0 * x + self.1
        }
    }
    type Link = Option<Box<Node>>;
    struct Node {
        line: Line,
        left: Link,
        right: Link,
    }
    impl Node {
        fn find(node: &Link, left: T, right: T, x: T) -> T {
            let mut node = node;
            let mut ans = INF;
            let mut l = left;
            let mut r = right;
            while let Some(t) = node.as_ref() {
                let val = t.line.eval(x);
                if compare(val, ans) == Ordering::Less {
                    ans = val;
                }
                let m = get_mid(l, r);
                node = if x <= m {
                    r = m;
                    &t.left
                } else {
                    l = m + 1;
                    &t.right
                };
            }
            ans
        }
        fn insert(node: &mut Link, l: T, r: T, mut line: Line) {
            if node.is_none() {
                *node = Some(Box::new(Node {
                    line: line,
                    left: None,
                    right: None,
                }));
                return;
            }
            let node = node.as_mut().unwrap();
            if compare(node.line.eval(l), line.eval(l)) == Ordering::Greater {
                std::mem::swap(&mut node.line, &mut line);
            }
            let m = get_mid(l, r);
            if compare(node.line.eval(r), line.eval(r)) != Ordering::Greater {
                return;
            } else if compare(node.line.eval(m), line.eval(m)) == Ordering::Less {
                Node::insert(&mut node.right, m + 1, r, line);
            } else {
                std::mem::swap(&mut node.line, &mut line);
                Node::insert(&mut node.left, l, m, line);
            }
        }
    }
    // [left, right]
    pub struct LiChaoTree {
        root: Link,
        left: T,
        right: T,
    }
    impl LiChaoTree {
        pub fn new(left: T, right: T) -> Self {
            LiChaoTree {
                root: None,
                left: left,
                right: right,
            }
        }
        pub fn insert(&mut self, a: T, b: T) {
            Node::insert(&mut self.root, self.left, self.right, Line(a, b));
        }
        pub fn find(&self, x: T) -> T {
            assert!(self.left <= x && x <= self.right);
            Node::find(&self.root, self.left, self.right, x)
        }
    }
}
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
        a: [i64; n],
    }
    let range_max = 200_000i64 * 10_000_000;
    let mut cht = lichao::LiChaoTree::new(-range_max, range_max);
    cht.insert(0, 0);
    let mut ans = 0;
    let mut sum = 0;
    let mut sum_k = 0;
    for (i, &a) in a.iter().enumerate() {
        let k = (i + 1) as i64;
        sum += a;
        sum_k += k * a;
        ans = std::cmp::max(ans, cht.find(sum) + sum_k);
        cht.insert(-k, -sum_k + k * sum);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
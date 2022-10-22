mod lichao {
    use std;
    use std::cmp::Ordering;
    type T = i64;
    const INF: T = std::i64::MIN;
    fn get_mid(l: T, r: T) -> T {
        (l + r) / 2
    }
    fn compare(l: T, r: T) -> Ordering {
        r.cmp(&l)
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
                node = if x < m {
                    r = m;
                    &t.left
                } else {
                    l = m;
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
            if compare(node.line.eval(r), line.eval(r)) == Ordering::Less {
                return;
            } else if compare(node.line.eval(m), line.eval(m)) == Ordering::Less {
                Node::insert(&mut node.right, m, r, line);
            } else {
                std::mem::swap(&mut node.line, &mut line);
                Node::insert(&mut node.left, l, m, line);
            }
        }
    }
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
            assert!(self.left <= x && x < self.right);
            Node::find(&self.root, self.left, self.right, x)
        }
    }
}

use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut rect: Vec<(i64, i64, i64)> = (0..n).map(|_| {
        let x: i64 = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();
        let a: i64 = it.next().unwrap().parse().unwrap();
        (x, y, a)
    }).collect();
    rect.sort();
    let mut cht = lichao::LiChaoTree::new(1, 1_000_000_000 + 1);
    cht.insert(0, 0);
    let mut ans = 0;
    for (x, y, a) in rect {
        let v = cht.find(y) + x * y - a;
        ans = std::cmp::max(ans, v);
        cht.insert(-x, v);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
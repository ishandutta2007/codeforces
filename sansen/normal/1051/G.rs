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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;

#[derive(Debug)]
struct Node {
    tri: i64,
    sum: i64,
    cnt: i64,
    left: Tree,
    right: Tree,
}

impl Node {
    fn update(&mut self) {
        let l = self.left.get();
        let r = self.right.get();
        self.tri = l.0 + l.1 * r.2 + r.0;
        self.sum = l.1 + r.1;
        self.cnt = l.2 + r.2;
    }
}

#[derive(Debug)]
struct Tree(Option<Box<Node>>);

impl Tree {
    fn get(&self) -> (i64, i64, i64) {
        self.0.as_ref().map_or((0, 0, 0), |p| (p.tri, p.sum, p.cnt))
    }
    fn insert(&mut self, l: i64, r: i64, x: i64, v: i64) {
        if self.0.is_none() {
            self.0 = Some(Box::new(Node {
                tri: 0,
                sum: 0,
                cnt: 0,
                left: Tree(None),
                right: Tree(None),
            }));
        }
        let node = self.0.as_mut().unwrap();
        if l + 1 == r {
            node.sum = v;
            node.cnt = 1;
            return;
        }
        let m = (l + r) / 2;
        if x < m {
            node.left.insert(l, m, x, v);
        } else {
            node.right.insert(m, r, x, v);
        }
        node.update();
    }
    fn merge(&mut self, rhs: Self) {
        if rhs.0.is_none() {
            return;
        }
        if self.0.is_none() {
            *self = rhs;
            return;
        }
        let node = self.0.as_mut().unwrap();
        let Node { left, right, .. } = *rhs.0.unwrap();
        node.left.merge(left);
        node.right.merge(right);
        node.update();
    }
}

fn run() {
    input! {
        n: usize,
        p: [(i64, i64); n],
    }
    let left = 1;
    let right = (200000 + n + 1) as i64;
    let mut map = Map::<(i64, i64), Tree>::new();
    let mut ans = 0i64;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (a, b) in p {
        let mut tree = Tree(None);
        tree.insert(left, right, b, b);
        let mut l = a;
        let mut r = a + 1;
        if let Some((&key, _)) = map.range(..=(l, right)).next_back() {
            if l <= key.1 {
                let p = map.remove(&key).unwrap();
                ans -= (l - key.0) * tree.get().1;
                ans -= p.get().0;
                tree.merge(p);
                l = key.0;
                r = key.1 + 1;
            }
        }
        if let Some((&key, _)) = map.range((l, r)..).next() {
            if key.0 <= r {
                let p = map.remove(&key).unwrap();
                ans -= (key.0 - l) * p.get().1;
                ans -= p.get().0;
                tree.merge(p);
                r +=  key.1 - key.0;
            }
        }
        ans += tree.get().0;
        map.insert((l, r), tree);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
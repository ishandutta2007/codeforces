// 
// 
// c_i
// 
//
//  x-y 
// 
//  S or rev S +c_i
// |S| >= 2 2
// aho dp?
// sum |S| <= 2000, 12
// 

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        p: [(i64, bytes); n],
    }
    let m = 12;
    let mut aho = AhoCorasick::new();
    let mut dp = vec![0];
    for (c, s) in p {
        let s = s.iter().map(|s| (*s - b'a') as usize).collect::<Vec<_>>();
        let mut set = Set::new();
        let mut g = vec![vec![]; m];
        for s in s.windows(2) {
            let (a, b) = (s[0], s[1]);
            if set.insert((a, b)) {
                set.insert((b, a));
                g[a].push(b);
                g[b].push(a);
            }
        }
        if g.iter().any(|g| g.len() > 2) {
            continue;
        }
        if let Some(x) = g.iter().position(|g| g.len() == 1) {
            let mut topo = vec![(x, x)];
            for i in 0.. {
                if i >= topo.len() {
                    break;
                }
                let (v, p) = topo[i];
                if let Some(&u) = g[v].iter().find(|x| **x != p) {
                    topo.push((u, v));
                }
            }
            if (0..m).all(|x| g[x].is_empty() || topo.iter().any(|p| p.0 == x)) {
                let s = topo.iter().map(|p| p.0).collect::<Vec<_>>();
                let rs = s.iter().cloned().rev().collect();
                for s in vec![s, rs] {
                    let x = aho.insert(&s);
                    if x >= dp.len() {
                        dp.resize(x + 1, 0);
                    }
                    dp[x] += c;
                }
            }
        }
    }
    aho.build();
    aho.bfs(|v, _, f| {
        dp[v] += dp[f];
    });
    let memo = dp;
    let size = memo.len();
    let inf = 10i64.pow(10);
    let mut dp = vec![vec![(-inf, (0, 0)); size]; 1 << m];
    dp[0][0] = (0, (0, 0));
    for bit in 0..(1 << m) {
        for x in 0..size {
            let (w, _) = dp[bit][x];
            if w < 0 {
                continue;
            }
            for i in 0..m {
                if bit >> i & 1 == 0 {
                    let u = aho.trans(x, i);
                    let w = w + memo[u];
                    dp[bit | (1 << i)][u].chmax((w, (bit, x)));
                }
            }
        }
    }
    let mut ans = vec![];
    let mut pos = ((1 << m) - 1, (0..size).max_by_key(|x| dp[(1 << m) - 1][*x]).unwrap());
    while pos.0 != 0 {
        let (_, (bit, v)) = dp[pos.0][pos.1];
        ans.push(b'a' + (bit ^ pos.0).trailing_zeros() as u8);
        pos = (bit, v);
    }
    println!("{}", ans.iter().map(|c| *c as char).collect::<String>());
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
// ---------- begin Aho-Corasick ----------
const F: usize = 26;

#[derive(Default)]
struct ACTrieNode {
    fail: usize,
    next: [usize; F],
}

pub struct AhoCorasick {
    node: Vec<ACTrieNode>,
}

impl AhoCorasick {
    pub fn new() -> Self {
        AhoCorasick {
            node: vec![ACTrieNode::default()],
        }
    }
    pub fn insert(&mut self, s: &[usize]) -> usize {
        let node = &mut self.node;
        let mut v = 0;
        for &k in s {
            if node[v].next[k] == 0 {
                node[v].next[k] = node.len();
                node.push(ACTrieNode::default());
            }
            v = node[v].next[k];
        }
        v
    }
    pub fn build(&mut self) {
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
    pub fn next(&self, v: usize, k: usize) -> usize {
        assert!(v < self.node.len() && k < F);
        self.node[v].next[k]
    }
    pub fn trans(&self, mut v: usize, k: usize) -> usize {
        assert!(v < self.node.len() && k < F);
        let node = &self.node;
        while v > 0 && node[v].next[k] == 0 {
            v = node[v].fail;
        }
        node[v].next[k]
    }
    pub fn fail(&self, v: usize) -> usize {
        assert!(v < self.node.len());
        self.node[v].fail
    }
    pub fn size(&self) -> usize {
        self.node.len()
    }
    pub fn bfs<F: FnMut(usize, &[usize], usize)>(&self, mut f: F) {
        let mut q = std::collections::VecDeque::new();
        q.push_back(0);
        while let Some(v) = q.pop_front() {
            f(v, &self.node[v].next, self.node[v].fail);
            for &u in self.node[v].next.iter() {
                if u != 0 {
                    q.push_back(u);
                }
            }
        }
    }
}
// ---------- end Aho-Corasick ----------
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
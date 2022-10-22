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
                    node[v].next[i] = node[node[v].fail].next[i];
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
    pub fn trans(&mut self, mut v: usize, k: usize) -> usize {
        assert!(v < self.node.len() && k < F);
        self.next(v, k)
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

fn run() {
    input! {
        s: bytes,
        t: bytes,
    }
    let mut aho = AhoCorasick::new();
    let t = t.iter().map(|t| (*t - b'a') as usize).collect::<Vec<_>>();
    let v = aho.insert(&t);
    aho.build();
    let inf = 10000000i32;
    let mut dp = vec![-inf; v + 1];
    dp[0] = 0;
    for &c in s.iter() {
        let mut next = vec![-inf; v + 1];
        for (u, &dp) in dp.iter().enumerate() {
            if c == b'?' {
                for k in 0..F {
                    next[aho.trans(u, k)].chmax(dp);
                }
            } else {
                let k = (c - b'a') as usize;
                next[aho.trans(u, k)].chmax(dp);
            }
        }
        next[v] += 1;
        dp = next;
    }
    let ans = dp.into_iter().max().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
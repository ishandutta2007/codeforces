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

use std::io::Write;

// N=Q=sum |S| 
// |S_k| > sqrt(N) 
// Aho-Corasick 
// failure link 
// hit
// k
// k  O(sum |S| + N + Q_k)
// sqrt(N) 
//
// |S_k| <= sqrt(N) 
//  Range Sum Query O(sqrt(N)) O(1) 
// Aho-Corasick 
// S_k S_k 
// 
// failure link 
// dfs
// RSQ 
// v
//  vk k 1
//  v
//   RSQhit
//  vu
//   dfs(u)
//  vk k 1
//  return
//
// TL 
// TL 
// 
// <=10^5
// 
//
// O(N^(1/2)), O(1) RSQ
// 

const B: usize = 300;

struct RSQ {
    sum: Vec<i32>,
    data: Vec<i32>,
}

impl RSQ {
    fn new(size: usize) -> Self {
        let size = (size + B) / B * B;
        let data = vec![0; size];
        let sum = vec![0; size / B + 1];
        Self {
            sum,
            data,
        }
    }
    fn add(&mut self, x: usize, v: i32) {
        let x = x + 1;
        let q = (x + B - 1) / B;
        for a in self.data[x..(q * B)].iter_mut() {
            *a += v;
        }
        for a in self.sum[q..].iter_mut() {
            *a += v;
        }
    }
    // [l, r)
    fn query(&self, l: usize, r: usize) -> i32 {
        self.sum[r / B] - self.sum[l / B] + self.data[r] - self.data[l]
    }
}

fn run() {
    input! {
        n: usize,
        q: usize,
        s: [bytes; n],
        ask: [(usize1, usize, usize1); q],
    }
    let s: Vec<Vec<usize>> = s
        .into_iter()
        .map(|s| s.into_iter().map(|c| (c - b'a') as usize).collect())
        .collect();
    let mut aho = AhoCorasick::new();
    let mut elem = vec![vec![]];
    for (i, s) in s.iter().enumerate() {
        let v = aho.insert(s);
        if v >= elem.len() {
            elem.resize(v + 1, vec![]);
        }
        elem[v].push(i);
    }
    aho.build();
    let size = aho.size();
    let mut ord = vec![];
    let mut child = vec![vec![]; size];
    aho.bfs(|v, _, f| {
        ord.push(v);
        if v > 0 {
            child[f].push(v);
        }
    });
    let mut query = vec![vec![]; n];
    for (k, &(l, r, x)) in ask.iter().enumerate() {
        query[x].push((l, r, k));
    }
    let mut ans = vec![0; q];

    // |S_k| > batch
    for (i, s) in s.iter().enumerate() {
        if s.len() <= B || query[i].is_empty() {
            continue;
        }
        let mut dp = vec![0; size];
        let mut pos = 0;
        for c in s {
            pos = aho.trans(pos, *c);
            dp[pos] += 1;
        }
        let mut sum = vec![0; n + 1];
        for &v in ord.iter().rev() {
            for &u in child[v].iter() {
                dp[v] += dp[u];
            }
            for &x in elem[v].iter() {
                sum[x] = dp[v];
            }
        }
        for i in (0..n).rev() {
            sum[i] += sum[i + 1];
        }
        for (l, r, k) in std::mem::take(&mut query[i]) {
            ans[k] = sum[l] - sum[r];
        }
    }

    // |S_k| <= batch
    let mut vertex = vec![vec![]; size];
    for (i, s) in s.iter().enumerate() {
        if s.len() > B {
            continue;
        }
        let mut pos = 0;
        for c in s {
            pos = aho.trans(pos, *c);
            vertex[pos].push(i);
        }
    }
    let mut rsq = RSQ::new(n + 1);
    enum Operation {
        Call(usize),
        End(usize),
    }
    let mut dfs = vec![Operation::Call(0)];
    while let Some(op) = dfs.pop() {
        match op {
            Operation::Call(v) => {
                dfs.push(Operation::End(v));
                for &x in elem[v].iter() {
                    rsq.add(x, 1);
                }
                for &k in vertex[v].iter() {
                    for &(l, r, x) in query[k].iter() {
                        ans[x] += rsq.query(l, r) as i64;
                    }
                }
                for &u in child[v].iter() {
                    dfs.push(Operation::Call(u));
                }
            },
            Operation::End(v) => {
                for &x in elem[v].iter() {
                    rsq.add(x, -1);
                }
            },
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
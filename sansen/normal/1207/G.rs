// ---------- begin fenwick tree ----------
#[allow(dead_code)]
mod fenwick {
    type T = i32;
    const ZERO: T = 0;
    pub struct Tree {
        a: Vec<T>,
    }
    impl Tree {
        pub fn new(n: usize) -> Tree {
            Tree {
                a: vec![ZERO; n + 1],
            }
        }
        pub fn add(&mut self, mut x: usize, v: T) {
            while x < self.a.len() {
                self.a[x] += v;
                x += x & (!x + 1);
            }
        }
        pub fn sum(&self, mut x: usize) -> T {
            debug_assert!(x < self.a.len());
            let mut res = ZERO;
            while x > 0 {
                res += self.a[x];
                x -= x & (!x + 1);
            }
            res
        }
    }
}
// ---------- end fenwick tree ----------
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
    fail: usize,
    next: [usize; F],
}

impl ACTrieNode {
    fn new() -> ACTrieNode {
        ACTrieNode {
            fail: 0,
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
                let t = ACTrieNode::new();
                node.push(t);
            }
            v = node[v].next[k];
        }
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
                    let f = node[v].fail;
                    node[v].next[i] = node[f].next[i];
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
    fn fail(&self, v: usize) -> usize {
        self.node[v].fail
    }
    fn get_size(&self) -> usize {
        self.node.len()
    }
}
// ---------- end Aho-Corasick ----------
//---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let mut g = vec![vec![]; n + 1];
    for i in 1..=n {
        let op: u8 = sc.next();
        if op == 1 {
            let c = convert(sc.next_chars())[0];
            g[0].push((i, c));
        } else {
            let j: usize = sc.next();
            let c = convert(sc.next_chars())[0];
            g[j].push((i, c));
        }
    }
    let mut ask = vec![vec![]; n + 1];
    let m: usize = sc.next();
    let mut aho = AhoCorasick::new();
    for i in 1..=m {
        let v: usize = sc.next();
        let s: Vec<usize> = convert(sc.next_chars());
        ask[v].push((i, aho.insert(&s)));
    }
    aho.build();
    let aho = aho;
    let len = aho.get_size();
    let mut fail_tree = vec![vec![]; len];
    for i in 1..len {
        let f = aho.fail(i);
        fail_tree[f].push(i);
    }
    let mut l = vec![0; len];
    let mut r = vec![0; len];
    euler_tour(0, &fail_tree, &mut l, &mut r, &mut 1);
    let mut bit = fenwick::Tree::new(len + 1);
    let mut ans = vec![0; m + 1];
    dfs(0, 0, &g, &ask, &mut ans, &l, &r, &aho, &mut bit);
    for &ans in &ans[1..] {
        writeln!(out, "{}", ans).ok();
    }
}

fn dfs(v: usize, state: usize, g: &Vec<Vec<(usize, usize)>>, ask: &Vec<Vec<(usize, usize)>>, ans: &mut [i32], l: &[usize], r: &[usize], aho: &AhoCorasick, bit: &mut fenwick::Tree) {
    bit.add(l[state], 1);
    for &(u, p) in &ask[v] {
        ans[u] = bit.sum(r[p] - 1) - bit.sum(l[p] - 1);
    }
    for &(u, k) in &g[v] {
        dfs(u, aho.next(state, k), g, ask, ans, l, r, aho, bit);
    }
    bit.add(l[state], -1);
}

fn euler_tour(v: usize, g: &Vec<Vec<usize>>, l: &mut [usize], r: &mut [usize], k: &mut usize) {
    l[v] = *k;
    *k += 1;
    for &u in &g[v] {
        euler_tour(u, g, l, r, k);
    }
    r[v] = *k;
}
// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
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
const F: usize = 10;

struct ACTrieNode {
    elem: bool,
    fail: usize,
    depth: usize,
    next: [usize; F],
}

impl ACTrieNode {
    fn new() -> ACTrieNode {
        ACTrieNode {
            elem: false,
            fail: 0,
            depth: 0,
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
                let mut t = ACTrieNode::new();
                t.depth = node[v].depth + 1;
                node.push(t);
            }
            v = node[v].next[k];
        }
        node[v].elem = true;
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
    fn trans(&self, mut v: usize, k: usize) -> usize {
        let node = &self.node;
        while v > 0 && node[v].next[k] == 0 {
            v = node[v].fail;
        }
        node[v].next[k]
    }
    fn elem(&self, k: usize) -> bool {
        self.node[k].elem
    }
    fn fail(&self, k: usize) -> usize {
        self.node[k].fail
    }
    fn depth(&self, k: usize) -> usize {
        self.node[k].depth
    }
    fn get_size(&self) -> usize {
        self.node.len()
    }
}
// ---------- end Aho-Corasick ----------
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

//

fn dfs(s: usize, x: usize, a: &mut Vec<usize>, res: &mut Vec<Vec<usize>>) {
    if s == x {
        let mut elem = false;
        for l in 0..a.len() {
            let mut sum = 0;
            for a in a[l..].iter() {
                sum += *a;
                elem |= sum < x && x % sum == 0;
            }
        }
        if !elem {
            res.push(a.clone());
        }
        return;
    }
    for i in 1..=std::cmp::min(x - s, 9) {
        a.push(i);
        dfs(s + i, x, a, res);
        a.pop();
    }
}

fn run() {
    input! {
        s: chars,
        x: usize,
    }
    let s = s.into_iter().map(|c| c.to_digit(10).unwrap() as usize).collect::<Vec<_>>();
    let mut res = vec![];
    dfs(0, x, &mut vec![], &mut res);
    let mut aho = AhoCorasick::new();
    let mut invalid = vec![];
    for a in res {
        let v = aho.insert(&a);
        invalid.push(v);
    }
    aho.build();
    let size = aho.get_size();
    let mut ok = vec![true; size];
    for v in invalid {
        ok[v] = false;
    }
    let inf = 1000 + 1;
    let mut dp = vec![inf; size];
    dp[0] = 0;
    for &c in s.iter() {
        let mut next = vec![inf; size];
        for (v, &dp) in dp.iter().enumerate() {
            if !ok[v] {
                continue;
            }
            next[v].chmin(dp + 1);
            let u = aho.trans(v, c);
            if ok[u] {
                next[u].chmin(dp);
            }
        }
        dp = next;
    }
    let ans = *dp.iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
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

type Ref = Box<Node>;
type Link = Option<Ref>;

#[derive(Default)]
struct Node {
    max: usize,
    next: [Link; 2],
}

const WIDTH: usize = 16;
const MID: usize = WIDTH / 2;

impl Node {
    fn new() -> Ref {
        Box::new(Node::default())
    }
    fn insert(&mut self, v: usize) {
        let mut po = self;
        for k in (MID..WIDTH).rev() {
            let x = (v >> k) & 1;
            po = po.next[x].get_or_insert_with(Node::new);
        }
        po.max = std::cmp::max(po.max, v & ((1 << MID) - 1));
    }
    fn find(&self, v: usize) -> usize {
        let mut ans = 0;
        let mut po = self;
        for k in (MID..WIDTH).rev() {
            let x = (v >> k) & 1;
            if let Some(p) = po.next[x ^ 1].as_ref() {
                ans |= 1 << k;
                po = p;
            } else {
                po = po.next[x].as_ref().unwrap();
            }
        }
        ans + po.max
    }
}

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [usize; n],
        e: [(usize1, usize1); n - 1],
        ask: [(usize1, usize1); q],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut depth = vec![0; n];
    let mut parent = vec![0; n];
    let mut stack = vec![0];
    while let Some(v) = stack.pop() {
        let child = std::mem::take(&mut g[v]);
        let d = depth[v] + 1;
        for &u in child.iter() {
            let k = g[u].iter().position(|p| *p == v).unwrap();
            g[u].remove(k);
            depth[u] = d;
            parent[u] = v;
            stack.push(u);
        }
        g[v] = child;
    }
    let batch = 1 << MID;
    let mut memo = vec![vec![]; n];
    let mut b_parent = vec![0; n];
    for (v, depth) in depth.iter().enumerate() {
        if *depth < batch {
            continue;
        }
        let mut node = Node::new();
        let mut pos = v;
        for d in 0..batch {
            node.insert(a[pos] ^ d);
            pos = parent[pos];
        }
        let mut res = vec![0; batch];
        for (i, res) in res.iter_mut().enumerate() {
            *res = node.find(i << MID);
        }
        memo[v] = res;
        b_parent[v] = pos;
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for &(u, mut v) in ask.iter() {
        let mut ans = 0;
        let mut d = 0;
        while depth[u] + batch <= depth[v] {
            ans = std::cmp::max(ans, memo[v][d >> MID]);
            d += batch;
            v = b_parent[v];
        }
        ans = std::cmp::max(ans, d ^ a[v]);
        while v != u {
            v = parent[v];
            d += 1;
            ans = std::cmp::max(ans, d ^ a[v]);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
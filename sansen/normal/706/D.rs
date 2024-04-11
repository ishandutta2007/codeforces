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

type Link = Option<Box<Node>>;

struct Node {
    cnt: u32,
    next: [Link; 2],
}

impl Node {
    fn new() -> Self {
        Node {
            cnt: 0,
            next: [None, None],
        }
    }
}

fn insert(po: &mut Link, x: usize, w: usize) {
    if po.is_none() {
        *po = Some(Box::new(Node::new()));
    }
    let po = po.as_mut().unwrap();
    po.cnt += 1;
    if w > 0 {
        let p = x >> (w - 1) & 1;
        insert(&mut po.next[p], x, w - 1);
    }
}

fn remove(node: &mut Link, x: usize, w: usize) {
    let po = node.as_mut().unwrap();
    po.cnt -= 1;
    if po.cnt == 0 {
        *node = None;
        return;
    }
    if w > 0 {
        let p = x >> (w - 1) & 1;
        remove(&mut po.next[p], x, w - 1);
    }
}

fn find(node: &Link, x: usize, w: usize) -> usize {
    if w == 0 {
        return 0;
    }
    let po = node.as_ref().unwrap();
    let p = x >> (w - 1) & 1;
    if po.next[p ^ 1].is_some() {
        find(&po.next[p ^ 1], x, w - 1) | (1 << (w - 1))
    } else {
        find(&po.next[p], x, w - 1)
    }
}

fn run() {
    input! {
        q: usize,
        ask: [(bytes, usize); q],
    }
    let mut root = None;
    let w = 30;
    insert(&mut root, 0, w);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, x) in ask {
        if op[0] == b'+' {
            insert(&mut root, x, w);
        } else if op[0] == b'-' {
            remove(&mut root, x, w);
        } else {
            let ans = find(&root, x, w);
            writeln!(out, "{}", ans).ok();
        }
    }
}

fn main() {
    run();
}
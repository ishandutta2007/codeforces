// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std;
    use std::io::Read;
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error"),
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::cmp::*;
use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

struct Node {
    max: i64,
    only: bool,
    sum: i64,
    len: i64,
}

impl Node {
    fn fold(&self, rhs: &Self) -> Self {
        let sum = self.sum + rhs.sum;
        let len = self.len + rhs.len;
        let (max, only) = match self.max.cmp(&rhs.max) {
            Ordering::Equal => (self.max, self.only && rhs.only),
            Ordering::Greater => (self.max, false),
            Ordering::Less => (rhs.max, false),
        };
        Node {
            max,
            only,
            sum,
            len,
        }
    }
    fn update_set(&mut self, v: i64) {
        self.sum = v * self.len;
        self.max = v;
        self.only = true;
    }
    fn break_mod(&self, v: i64) -> bool {
        self.max < v
    }
    fn tag_mod(&self, v: i64) -> bool {
        self.max >= v && self.only
    }
    fn update_mod(&mut self, v: i64) {
        assert!(self.tag_mod(v));
        let x = self.max % v;
        self.update_set(x);
    }
}

fn propagate(k: usize, node: &mut [Node]) {
    assert!(2 * k + 1 < node.len());
    if node[k].only {
        node[2 * k].update_set(node[k].max);
        node[2 * k + 1].update_set(node[k].max);
    }
}

fn update_set(k: usize, l: usize, r: usize, x: usize, y: usize, v: i64, node: &mut [Node]) {
    if y <= l || r <= x {
        return;
    }
    if x <= l && r <= y {
        node[k].update_set(v);
        return;
    }
    propagate(k, node);
    let m = (l + r) / 2;
    update_set(2 * k, l, m, x, y, v, node);
    update_set(2 * k + 1, m, r, x, y, v, node);
    node[k] = node[2 * k].fold(&node[2 * k + 1]);
}

fn update_mod(k: usize, l: usize, r: usize, x: usize, y: usize, v: i64, node: &mut [Node]) {
    if y <= l || r <= x || node[k].break_mod(v) {
        return;
    }
    if x <= l && r <= y && node[k].tag_mod(v) {
        node[k].update_mod(v);
        return;
    }
    propagate(k, node);
    let m = (l + r) / 2;
    update_mod(2 * k, l, m, x, y, v, node);
    update_mod(2 * k + 1, m, r, x, y, v, node);
    node[k] = node[2 * k].fold(&node[2 * k + 1]);
}

fn find_sum(k: usize, l: usize, r: usize, x: usize, y: usize, node: &mut [Node]) -> i64 {
    if y <= l || r <= x {
        return 0;
    }
    if x <= l && r <= y {
        return node[k].sum;
    }
    propagate(k, node);
    let m = (l + r) / 2;
    find_sum(2 * k, l, m, x, y, node) + find_sum(2 * k + 1, m, r, x, y, node)
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let m: usize = sc.next();
    let size = n.next_power_of_two();
    let mut node = (0..(2 * size))
        .map(|_| Node {
            max: 0,
            only: true,
            sum: 0,
            len: 1,
        })
        .collect::<Vec<_>>();
    for node in node[size..].iter_mut().take(n) {
        node.len = 1;
        node.update_set(sc.next());
    }
    for i in (1..size).rev() {
        node[i] = node[2 * i].fold(&node[2 * i + 1]);
    }
    for _ in 0..m {
        let op: u8 = sc.next();
        if op == 1 {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let ans = find_sum(1, 0, size, l, r, &mut node);
            writeln!(out, "{}", ans).ok();
        } else if op == 2 {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let x = sc.next::<i64>();
            update_mod(1, 0, size, l, r, x, &mut node);
        } else {
            let k = sc.next::<usize>() - 1;
            let x = sc.next::<i64>();
            update_set(1, 0, size, k, k + 1, x, &mut node);
        }
    }
}
// ---------- begin scannner ----------
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
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let q: usize = sc.next();
    let mut w = 0;
    while 1 << w <= 100_000_000 {
        w += 1;
    }
    let mut add = None;
    let mut sub = None;
    for _ in 0..q {
        let op: u8 = sc.next();
        let p: usize = sc.next();
        if op == 1 {
            insert(&mut add, w, p);
        } else if op == 2 {
            insert(&mut sub, w, p);
        } else {
            let l: usize = sc.next();
            let ans = count_less(&add, w, p, l) - count_less(&sub, w, p, l);
            writeln!(out, "{}", ans).ok();
        }
    }
}


type Link = Option<Box<Node>>;

struct Node {
    cnt: u32,
    next: [Link; 2],
}

fn insert(node: &mut Link, w: usize, v: usize) {
    if node.is_none() {
        *node = Some(Box::new(Node {
            cnt: 0,
            next: [None, None],
        }));
    }
    let node = node.as_mut().unwrap();
    node.cnt += 1;
    if w > 0 {
        insert(&mut node.next[(v >> (w - 1)) & 1], w - 1, v);
    }
}

// (x ^ p) < y 
fn count_less(node: &Link, w: usize, x: usize, y: usize) -> u32 {
    if node.is_none() || w == 0 {
        return 0;
    }
    let node = node.as_ref().unwrap();
    let mut res = 0;
    let a = x >> (w - 1) & 1;
    let b = y >> (w - 1) & 1;
    if b == 1 {
        res += node.next[a].as_ref().map_or(0, |p| p.cnt);
        res += count_less(&node.next[a ^ 1], w - 1, x, y);
    } else {
        res += count_less(&node.next[a], w - 1, x, y);
    }
    res
}
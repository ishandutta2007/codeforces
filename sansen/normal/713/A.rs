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
    let t: usize = sc.next();
    let mut add = None;
    let mut sub = None;
    for _ in 0..t {
        let op = sc.next_chars()[0];
        let mut s = sc.next_chars().into_iter().map(|c| (c.to_digit(10).unwrap() % 2) as usize).collect::<Vec<_>>();
        while s.len() < 18 {
            s.insert(0, 0);
        }
        if op == '+' {
            insert(&mut add, &s);
        } else if op == '-' {
            insert(&mut sub, &s);
        } else {
            let ans = count(&add, &s) - count(&sub, &s);
            writeln!(out, "{}", ans).ok();
        }
    }
}

type Link = Option<Box<Node>>;
struct Node {
    cnt: u32,
    next: [Link; 2],
}

fn insert(node: &mut Link, s: &[usize]) {
    if node.is_none() {
        *node = Some(Box::new(Node {
            cnt: 0,
            next: [None, None],
        }));
    }
    let node = node.as_mut().unwrap();
    node.cnt += 1;
    if s.len() > 0 {
        let k = s[0];
        insert(&mut node.next[k], &s[1..]);
    }
}

fn count(node: &Link, s: &[usize]) -> u32 {
    if node.is_none() {
        return 0;
    }
    let node = node.as_ref().unwrap();
    if s.len() == 0 {
        node.cnt
    } else {
        count(&node.next[s[0]], &s[1..])
    }
}
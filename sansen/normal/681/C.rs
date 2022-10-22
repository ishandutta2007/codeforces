// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
        pub fn next_bytes(&mut self) -> Vec<u8> {
            self.it.next().unwrap().bytes().collect()
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.it.next().unwrap().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut ans = vec![];
    let mut h = std::collections::BinaryHeap::<i32>::new();
    for _ in 0..n {
        let op: String = sc.next();
        if op == "insert" {
            let x: i32 = sc.next();
            ans.push(String::from(&format!("insert {}", x)));
            h.push(-x);
        } else if op == "getMin" {
            let x: i32 = sc.next();
            while h.peek().map_or(false, |p| -*p < x) {
                h.pop();
                ans.push(String::from(&format!("removeMin")));
            }
            if h.peek().map_or(true, |p| -*p != x) {
                h.push(-x);
                ans.push(String::from(&format!("insert {}", x)));
            }
            ans.push(String::from(&format!("getMin {}", x)));
        } else {
            if h.is_empty() {
                ans.push(String::from("insert 1"));
            }
            ans.push(op);
            h.pop();
        }
    }
    writeln!(out, "{}", ans.len()).ok();
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}
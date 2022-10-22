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

#[derive(Clone, Copy)]
enum Logic {
    IN(u8, usize),
    AND(usize, usize, u8, u8),
    OR(usize, usize, u8, u8),
    XOR(usize, usize),
    NOT(usize),
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut g = vec![Logic::NOT(0); n];
    let mut id = 0;
    for g in g.iter_mut() {
        let s = sc.next::<String>();
        if s == "IN" {
            let ini = sc.next::<u8>();
            *g = Logic::IN(ini, id);
            id += 1;
        } else if s == "NOT" {
            let v = sc.next::<usize>() - 1;
            *g = Logic::NOT(v);
        } else {
            let a = sc.next::<usize>() - 1;
            let b = sc.next::<usize>() - 1;
            if s == "XOR" {
                *g = Logic::XOR(a, b);
            } else {
                *g = if s == "AND" { Logic::AND } else { Logic::OR }(a, b, 0, 0);
            }
        }
    }
    let val = eval(0, &mut g);
    let mut ans = vec![val; id];
    dfs(0, 1, &g, &mut ans);
    let mut s = String::new();
    for a in ans {
        s.push((b'0' + a) as char);
    }
    println!("{}", s);
}

fn dfs(v: usize, flip: u8, g: &[Logic], ans: &mut [u8]) {
    match g[v] {
        Logic::IN(_, k) => ans[k] ^= flip,
        Logic::NOT(u) => dfs(u, flip, g, ans),
        Logic::AND(a, b, x, y) => {
            dfs(a, flip & y, g, ans);
            dfs(b, flip & x, g, ans);
        }
        Logic::OR(a, b, x, y) => {
            dfs(a, flip & (y ^ 1), g, ans);
            dfs(b, flip & (x ^ 1), g, ans);
        }
        Logic::XOR(a, b) => {
            dfs(a, flip, g, ans);
            dfs(b, flip, g, ans);
        }
    }
}

fn eval(v: usize, g: &mut [Logic]) -> u8 {
    match g[v] {
        Logic::IN(ini, _) => ini,
        Logic::NOT(u) => 1 ^ eval(u, g),
        Logic::AND(a, b, _, _) => {
            let x = eval(a, g);
            let y = eval(b, g);
            g[v] = Logic::AND(a, b, x, y);
            x & y
        }
        Logic::OR(a, b, _, _) => {
            let x = eval(a, g);
            let y = eval(b, g);
            g[v] = Logic::OR(a, b, x, y);
            x | y
        }
        Logic::XOR(a, b) => eval(a, g) ^ eval(b, g),
    }
}
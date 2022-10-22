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
// ---------- begin Scanner(require delimiter) ----------
mod scanner {
    pub struct Scanner<R> {
        reader: R,
        buf: Vec<u8>,
    }
    #[allow(dead_code)]
    impl<R: std::io::BufRead> Scanner<R> {
        pub fn new(reader: R) -> Self {
            Scanner {
                reader: reader,
                buf: Vec::with_capacity(1024),
            }
        }
        fn read(&mut self, del: u8) {
            self.buf.clear();
            self.reader.read_until(del, &mut self.buf).ok();
            assert!(self.buf.pop().unwrap() == del);
        }
        pub fn next<T: std::str::FromStr>(&mut self, del: u8) -> T {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .parse::<T>()
                .ok()
                .unwrap()
        }
        pub fn next_bytes(&mut self, del: u8) -> Vec<u8> {
            self.read(del);
            std::str::from_utf8(&self.buf)
                .unwrap()
                .trim()
                .bytes()
                .collect()
        }
    }
}
// ---------- end scanner(require delimiter) ----------

use std::io::Write;

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

type Ref = Box<Node>;
type Link = Option<Ref>;

struct Node {
    min: usize,
    next: [Link; 2],
}

impl Default for Node {
    fn default() -> Self {
        Node {
            min: (1 << LEN) - 1,
            next: Default::default(),
        }
    }
}

const LEN: usize = 17;

impl Node {
    fn new() -> Ref {
        Box::new(Node::default())
    }
    fn insert(&mut self, v: usize) {
        let mut po = self;
        for i in (0..LEN).rev() {
            po.min.chmin(v);
            po = po.next[v >> i & 1].get_or_insert_with(Node::new);
        }
        po.min.chmin(v);
    }
    fn find(&self, x: usize, s: usize) -> usize {
        assert!(self.min + x <= s);
        let mut po = self;
        let mut ans = 0;
        for i in (0..LEN).rev() {
            let k = x >> i & 1;
            if po.next[k ^ 1].as_ref().map_or(false, |p| p.min + x <= s) {
                ans |= 1 << i;
                po = po.next[k ^ 1].as_ref().unwrap();
            } else {
                po = po.next[k].as_ref().unwrap();
            }
        }
        ans ^ x
    }
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let w = 100_000;
    let mut f = (0..=w).collect::<Vec<_>>();
    for p in (2..).take_while(|p| p * p <= w) {
        if p == f[p] {
            for j in p..=(w / p) {
                f[j * p] = p;
            }
        }
    }
    let factor = f;
    let factorize = |v: usize| -> Vec<usize> {
        let mut ans = vec![1];
        let mut v = v;
        while v > 1 {
            let p = factor[v];
            let mut cnt = 0;
            while v % p == 0 {
                v /= p;
                cnt += 1;
            }
            let len = ans.len();
            let mut mul = 1;
            for _ in 0..cnt {
                mul *= p;
                for i in 0..len {
                    let v = ans[i] * mul;
                    ans.push(v);
                }
            }
        }
        ans
    };
    let mut node = (0..=w).map(|_| Node::new()).collect::<Vec<_>>();
    let mut used = vec![false; w + 1];
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let q: usize = sc.next(b'\n');
    for _ in 0..q {
        let op: u8 = sc.next(b' ');
        if op == 1 {
            let u: usize = sc.next(b'\n');
            if !used[u] {
                used[u] = true;
                for f in factorize(u) {
                    node[f].insert(u);
                }
            }
        } else {
            let x: usize = sc.next(b' ');
            let k: usize = sc.next(b' ');
            let s: usize = sc.next(b'\n');
            if x % k != 0 || node[k].min + x > s {
                writeln!(out, "-1").ok();
            } else {
                writeln!(out, "{}", node[k].find(x, s)).ok();
            }
        }
    }
}
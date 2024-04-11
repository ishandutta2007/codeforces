struct Graph {
    size: usize,
    edge: Vec<u64>,
}

impl Graph {
    fn new(size: usize) -> Self {
        assert!(std::mem::size_of::<u64>() * 8 >= size);
        Graph {
            size: size,
            edge: (0..size).map(|x| 1u64 << x as u64).collect(),
        }
    }
    fn add_edge(&mut self, s: usize, t: usize) {
        assert!(s != t);
        self.edge[s] |= 1u64 << t as u64;
        self.edge[t] |= 1u64 << s as u64;
    }
    fn rec(&self, rem: u64) -> Vec<usize> {
        if rem == 0 {
            return vec![];
        }
        let mut max_deg = (0, 0);
        let mut bit = rem;
        while bit > 0 {
            let x = bit & (!bit + 1);
            bit -= x;
            let x = x.trailing_zeros() as usize;
            let deg = (self.edge[x] & rem).count_ones();
            if deg <= 2 {
                let mut ans = self.rec(rem & !self.edge[x]);
                ans.push(x);
                return ans;
            }
            max_deg = std::cmp::max(max_deg, (deg, x));
        }
        let v = max_deg.1;
        let mut ans = self.rec(rem & !self.edge[v]);
        ans.push(v);
        if max_deg.0 <= 3 {
            return ans;
        }
        let q = self.rec(rem & !(1u64 << v as u64));
        if q.len() > ans.len() {
            q
        } else {
            ans
        }
    }
    fn solve(&self) -> Vec<usize> {
        let mask = if self.size == std::mem::size_of::<u64>() * 8 {
            std::u64::MAX
        } else {
            (1u64 << self.size as u64) - 1
        };
        self.rec(mask)
    }
}

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
    let m: usize = sc.next();
    let mut cnt = 0;
    let mut set = std::collections::BTreeSet::new();
    let mut v = vec![];
    let mut map = std::collections::BTreeMap::new();
    let mut e = vec![];
    for _ in 0..n {
        let op: u8 = sc.next();
        if op == 2 {
            let s: String = sc.next();
            if set.insert(s.clone()) {
                map.insert(s.clone(), cnt);
                cnt += 1;
            }
            let id = *map.get(&s).unwrap();
            v.push(id);
        } else {
            v.sort();
            v.dedup();
            for (i, a) in v.iter().enumerate() {
                for b in v.iter().take(i) {
                    e.push((*a, *b));
                }
            }
            v.clear();
        }
    }
    v.sort();
    v.dedup();
    for (i, a) in v.iter().enumerate() {
        for b in v.iter().take(i) {
            e.push((*a, *b));
        }
    }

    e.sort();
    e.dedup();
    let mut g = Graph::new(m);
    for (a, b) in e {
        g.add_edge(a, b);
    }
    let ans = g.solve().len();
    writeln!(out, "{}", ans).ok();
}
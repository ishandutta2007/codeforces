// ---------- begin SegmentTree Range update Point query ----------
mod segment_tree {
    pub struct RUPQ<T, F> {
        size: usize,
        data: Vec<T>,
        op: F,
    }
    impl<T, F> RUPQ<T, F>
    where
        T: Clone,
        F: Fn(&T, &T) -> T,
    {
        pub fn new(size: usize, e: T, op: F) -> Self {
            let size = size.next_power_of_two();
            Self {
                size,
                data: vec![e.clone(); 2 * size],
                op,
            }
        }
        pub fn find(&self, x: usize) -> T {
            assert!(x < self.size);
            let mut x = x + self.size;
            let mut ans = self.data[x].clone();
            while x > 1 {
                x >>= 1;
                ans = (self.op)(&ans, &self.data[x]);
            }
            ans
        }
        pub fn update(&mut self, l: usize, r: usize, f: T) {
            assert!(l <= r && r <= self.size);
            if l == r {
                return;
            }
            let mut l = l + self.size;
            let mut r = r + self.size;
            while l < r {
                if l & 1 == 1 {
                    self.data[l] = (self.op)(&self.data[l], &f);
                    l += 1;
                }
                if r & 1 == 1 {
                    r -= 1;
                    self.data[r] = (self.op)(&self.data[r], &f);
                }
                l >>= 1;
                r >>= 1;
            }
        }
    }
}
// ---------- end SegmentTree Range update Point query ----------
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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

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
    let q: usize = sc.next();
    let mut map = Map::new();
    // 
    map.insert(0, (n, 1, 0));
    let mut add = vec![0; n + 1];
    let mut seg = segment_tree::RUPQ::new(n, 0, |a, b| *a + *b);
    for _ in 0..q {
        let op: String = sc.next();
        let op = op.as_str();
        if op == "Color" {
            let l = sc.next::<usize>() - 1;
            let r = sc.next::<usize>();
            let c = sc.next::<usize>();
            for &p in [l, r].iter() {
                let (&l, &(r, c, v)) = map.range(..=p).next_back().unwrap();
                if r > p {
                    map.remove(&l);
                    map.insert(l, (p, c, v));
                    map.insert(p, (r, c, v));
                }
            }
            while let Some((&l, &(r, c, v))) = map.range(l..r).next() {
                map.remove(&l);
                seg.update(l, r, add[c] - v);
            }
            map.insert(l, (r, c, add[c]));
        } else if op == "Add" {
            let c: usize = sc.next();
            let x: i64 = sc.next();
            add[c] += x;
        } else {
            let x = sc.next::<usize>() - 1;
            let (_, &(_, c, v)) = map.range(..=x).next_back().unwrap();
            let ans = seg.find(x) + add[c] - v;
            writeln!(out, "{}", ans).ok();
        }
    }
}
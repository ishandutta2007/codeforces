//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    use std;
    pub struct UF {
        parent: Vec<usize>,
        size: Vec<usize>,
        stack: Vec<Option<(usize, usize)>>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            let mut u = UF {
                parent: vec![0; n],
                size: vec![1; n],
                stack: vec![],
            };
            u.init();
            u
        }
        pub fn init(&mut self) {
            for (i, p) in self.parent.iter_mut().enumerate() {
                *p = i;
            }
            self.size.clear();
            self.size.resize(self.parent.len(), 1);
            self.stack.clear();
        }
        pub fn root(&mut self, mut x: usize) -> usize {
            while self.parent[x] != x {
                x = self.parent[x];
            }
            x
        }
        pub fn same(&mut self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                self.stack.push(None);
                return None;
            }
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.size[x] += self.size[y];
            self.parent[y] = x;
            self.stack.push(Some((x, y)));
            Some((x, y))
        }
        pub fn undo(&mut self) -> Option<(usize, usize)> {
            self.stack
                .pop()
                .expect("union find undo error: stack is empty")
                .map(|(x, y)| {
                    self.size[x] -= self.size[y];
                    self.parent[y] = y;
                    (x, y)
                })
        }
        pub fn get_size(&mut self, x: usize) -> usize {
            let r = self.root(x);
            self.size[r]
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            if self.parent[x] == x {
                None
            } else {
                Some(self.parent[x])
            }
        }
    }
}
//---------- end union_find ----------
// ---------- end Scanner(require delimiter) ----------
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

fn main() {
    let stdin = std::io::stdin();
    let mut sc = scanner::Scanner::new(stdin.lock());
    run(&mut sc);
}

fn run<R: std::io::BufRead>(sc: &mut scanner::Scanner<R>) {
    let n: usize = sc.next(b' ');
    let m: usize = sc.next(b'\n');
    let mut map = std::collections::BTreeMap::new();
    for _ in 0..m {
        let x = sc.next::<usize>(b' ') - 1;
        let y = sc.next::<usize>(b' ') - 1;
        let d = sc.next::<u32>(b'\n');
        map.insert((x, y), (d, 0));
    }
    let q: usize = sc.next(b'\n');
    let mut edge = vec![];
    let mut ask = vec![];
    let mut timer = 0;
    for _ in 0..q {
        let op = sc.next(b' ');
        match op {
            1 => {
                let x = sc.next::<usize>(b' ') - 1;
                let y = sc.next::<usize>(b' ') - 1;
                let d: u32 = sc.next(b'\n');
                assert!(map.insert((x, y), (d, timer)).is_none());
            },
            2 => {
                let x = sc.next::<usize>(b' ') - 1;
                let y = sc.next::<usize>(b'\n') - 1;
                let (d, k) = map.remove(&(x, y)).unwrap();
                if k < timer {
                    edge.push((x, y, d, k, timer));
                }
            },
            3 => {
                let x = sc.next::<usize>(b' ') - 1;
                let y = sc.next::<usize>(b'\n') - 1;
                ask.push((x, y));
                timer += 1;
            },
            _ => unreachable!(),
        }
    }
    for ((x, y), (d, k)) in map {
        if k < timer {
            edge.push((x, y, d, k, timer));
        }
    }
    let mut ans = vec![std::u32::MAX; ask.len()];
    let mut u = union_find::UF::new(n);
    let mut dp = vec![0u32; n];
    calc(0, timer, &ask, &mut ans, &mut u, &mut dp, edge, vec![]);
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn calc(l: usize, r: usize, ask: &[(usize, usize)], ans: &mut [u32], u: &mut union_find::UF, dp: &mut [u32], edge: Vec<(usize, usize, u32, usize, usize)>, mut base: Vec<u32>) {
    let mut left = vec![];
    let mut right = vec![];
    let mid = (l + r) / 2;
    let mut cnt = 0;
    for (x, y, d, p, q) in edge {
        if p <= l && r <= q {
            cnt += 1;
            if let Some((a, b)) = u.unite(x, y) {
                assert!(dp[a] == 0 && dp[b] == 0);
                let mut xor = d;
                for mut x in [x, y].iter().cloned() {
                    while let Some(p) = u.parent(x) {
                        xor ^= dp[x];
                        x = p;
                    }
                }
                dp[b] = xor;
            } else {
                let mut xor = d;
                for mut x in [x, y].iter().cloned() {
                    while let Some(p) = u.parent(x) {
                        xor ^= dp[x];
                        x = p;
                    }
                }
                for base in base.iter() {
                    xor = std::cmp::min(xor, *base ^ xor);
                }
                if xor > 0 {
                    base.push(xor);
                }
            }
            continue;
        }
        if p < mid {
            left.push((x, y, d, p, q));
        }
        if mid < q {
            right.push((x, y, d, p, q));
        }
    }
    if l + 1 == r {
        let (x, y) = ask[l];
        let mut xor = 0;
        for mut x in [x, y].iter().cloned() {
            while let Some(p) = u.parent(x) {
                xor ^= dp[x];
                x = p;
            }
        }
        for base in base.iter() {
            xor = std::cmp::min(xor, *base ^ xor);
        }
        ans[l] = xor;
    } else {
        calc(l, mid, ask, ans, u, dp, left, base.clone());
        calc(mid, r, ask, ans, u, dp, right, base);
    }
    for _ in 0..cnt {
        if let Some((a, b)) = u.undo() {
            assert!(dp[a] == 0);
            dp[b] = 0;
        }
    }
}
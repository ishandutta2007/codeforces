// https://twitter.com/noshi91/status/1355202316354248705
// 
// new(size): 
// insert(x): x (x < size)
// remove(x): x (x < size)
// enumerate():  () 
// 
// 
// size, size + 1 
// node[x] = (c, f, t): x c  c > 0  f, t 
// ---------- begin enumerate set ----------
pub struct EnumerateSet {
    size: usize,
    node: Vec<(u32, u32, u32)>,
}

impl EnumerateSet {
    pub fn new(size: usize) -> Self {
        let node = vec![(0, size as u32, size as u32 + 1); size + 2];
        Self {
            size: size,
            node: node,
        }
    }
    pub fn insert(&mut self, x: usize) {
        assert!(x < self.size);
        if self.node[x].0 == 0 {
            let f = self.size as usize;
            let t = self.node[f].2 as usize;
            self.node[x] = (0, f as u32, t as u32);
            self.node[f].2 = x as u32;
            self.node[t].1 = x as u32;
        }
        self.node[x].0 += 1;
    }
    pub fn remove(&mut self, x: usize) {
        assert!(x < self.size);
        if self.node[x].0 == 0 {
            return;
        }
        self.node[x].0 -= 1;
        if self.node[x].0 == 0 {
            let (_, f, t) = self.node[x];
            self.node[f as usize].2 = t;
            self.node[t as usize].1 = f;
        }
    }
    // key, cnt
    pub fn enumerate(&self) -> Vec<(usize, u32)> {
        let mut ans = vec![];
        let mut pos = self.node[self.size].2 as usize;
        while pos != self.size + 1 {
            let (c, _, t) = self.node[pos];
            ans.push((pos, c));
            pos = t as usize;
        }
        ans
    }
}
// ---------- end enumerate set ----------
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
    let a: Vec<usize> = (0..n).map(|_| sc.next::<usize>() - 1).collect();
    let mut query = vec![(0u8, 0usize, 0usize, 0usize); m];
    for q in query.iter_mut() {
        q.0 = sc.next();
        q.1 = sc.next();
        q.1 -= 1;
        q.2 = sc.next();
        if q.0 == 1 {
            q.3 = sc.next();
        }
    }
    let param = (n as f64).cbrt().powi(2).ceil() as usize;
    let mut update = vec![];
    let mut ask = vec![vec![vec![]; n / param + 1]; n / param + 1];
    for (i, (op, l, r, x)) in query.into_iter().enumerate() {
        if op == 1 {
            ask[l / param][r / param].push((l, r, x, i));
        } else {
            update.push((i, l, r - 1));
        }
    }
    let mut ans = vec![None; m];
    struct State {
        set: EnumerateSet,
        cnt: Vec<usize>,
    }
    impl State {
        fn new(size: usize) -> Self {
            State {
                set: EnumerateSet::new(size + 1),
                cnt: vec![0; size + 1],
            }
        }
        fn init(&mut self) {
            for cnt in self.cnt.iter_mut() {
                self.set.remove(*cnt);
                *cnt = 0;
            }
        }
        fn add(&mut self, x: usize) {
            let po = &mut self.cnt[x];
            if *po > 0 {
                self.set.remove(*po);
            }
            *po += 1;
            self.set.insert(*po);
        }
        fn sub(&mut self, x: usize) {
            let po = &mut self.cnt[x];
            self.set.remove(*po);
            *po -= 1;
            if *po > 0 {
                self.set.insert(*po);
            }
        }
    }
    let size = 100_000;
    let mut state = State::new(size);
    for ask in ask.into_iter().flatten().filter(|ask| !ask.is_empty()) {
        let mut a = a.clone();
        state.init();
        let mut x = 0;
        let mut y = 0;
        let mut z = 0;
        for (l, r, k, t) in ask {
            while update.get(z).map_or(false, |p| p.0 <= t) {
                let (_, p, v) = update[z];
                z += 1;
                if x <= p && p < y {
                    state.sub(a[p]);
                    state.add(v);
                }
                a[p] = v;
            }
            while y < r {
                state.add(a[y]);
                y += 1;
            }
            while l < x {
                x -= 1;
                state.add(a[x]);
            }
            while r < y {
                y -= 1;
                state.sub(a[y]);
            }
            while x < l {
                state.sub(a[x]);
                x += 1;
            }
            let mut list = state.set.enumerate();
            if (list.iter().fold(0, |s, p| s + p.1) as usize) < k {
                ans[t] = Some(-1);
            } else {
                list.sort_by_key(|p| p.0);
                let mut val = std::i32::MAX;
                let mut sum = 0;
                let mut x = 0;
                for i in 0..list.len() {
                    while x < list.len() && sum < k {
                        sum += list[x].1 as usize;
                        x += 1;
                    }
                    if sum >= k {
                        val = val.min((list[i].0 as i32 - list[x - 1].0 as i32).abs());
                    }
                    sum -= list[i].1 as usize;
                }
                ans[t] = Some(val);
            }
        }
    }
    for a in ans {
        if let Some(a) = a {
            writeln!(out, "{}", a).ok();
        }
    }
}
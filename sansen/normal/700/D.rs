fn read() -> (Vec<usize>, Vec<(usize, usize)>) {
    use std::io::*;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let mut next = || it.next().unwrap();
    let n: usize = next().parse().unwrap();
    let a = (0..n).map(|_| next().parse::<usize>().unwrap()).collect::<Vec<_>>();
    let q: usize = next().parse().unwrap();
    let ask = (0..q).map(|_| {
        let l = next().parse::<usize>().unwrap() - 1;
        let r = next().parse::<usize>().unwrap();
        (l, r)
    }).collect::<Vec<_>>();
    (a, ask)
}

pub struct EnumerateSet {
    size: usize,
    node: Vec<(usize, usize, usize)>,
}

impl EnumerateSet {
    pub fn new(size: usize) -> Self {
        let node = vec![(0, size, size + 1); size + 2];
        Self {
            size: size,
            node: node,
        }
    }
    pub fn insert(&mut self, x: usize) {
        assert!(x < self.size);
        if self.node[x].0 == 0 {
            let f = self.size;
            let t = self.node[f].2;
            self.node[x] = (0, f, t);
            self.node[f].2 = x;
            self.node[t].1 = x;
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
            self.node[f].2 = t;
            self.node[t].1 = f;
        }
    }
    // key, cnt
    pub fn enumerate(&self) -> Vec<(usize, usize)> {
        let mut ans = vec![];
        let mut pos = self.node[self.size].2;
        while pos != self.size + 1 {
            let (c, _, t) = self.node[pos];
            ans.push((pos, c));
            pos = t;
        }
        ans
    }
}

struct State {
    cnt: Vec<usize>,
    set: EnumerateSet,
}

impl State {
    fn new(size: usize) -> Self {
        Self {
            cnt: vec![0; size],
            set: EnumerateSet::new(size + 1),
        }
    }
    fn insert(&mut self, x: usize) {
        let c = &mut self.cnt[x];
        if *c > 0 {
            self.set.remove(*c);
        }
        *c += 1;
        self.set.insert(*c);
    }
    fn remove(&mut self, x: usize) {
        let c = &mut self.cnt[x];
        assert!(*c > 0);
        self.set.remove(*c);
        *c -= 1;
        if *c > 0 {
            self.set.insert(*c);
        }
    }
    fn solve(&self) -> usize {
        let mut p = self.set.enumerate();
        p.sort();
        type Q = std::collections::VecDeque<(usize, usize)>;
        let mut h = Q::new();
        let mut q = p.into_iter().collect::<Q>();
        let mut ans = 0;
        h.push_back(q.pop_front().unwrap());
        loop {
            let (a, x) = h.pop_front().unwrap();
            if x == 1 && h.is_empty() && q.is_empty() {
                break;
            }
            if x > 1 {
                let m = x / 2;
                ans += 2 * m * a;
                while q.front().map_or(false, |p| p.0 <= 2 * a) {
                    h.push_back(q.pop_front().unwrap());
                }
                h.push_back((2 * a, m));
                if x % 2 == 1 {
                    h.push_front((a, 1));
                }
            } else {
                if h.is_empty() {
                    h.push_back(q.pop_front().unwrap());
                }
                let (b, y) = h.pop_front().unwrap();
                ans += a + b;
                while q.front().map_or(false, |p| p.0 <= a + b) {
                    h.push_back(q.pop_front().unwrap());
                }
                if y > 1 {
                    h.push_front((b, y - 1));
                }
                h.push_back((a + b, 1));
            }
        }
        ans
    }
}

fn main() {
    let (mut a, ask) = read();
    let mut z = a.clone();
    z.sort();
    z.dedup();
    for a in a.iter_mut() {
        *a = z.binary_search(a).unwrap();
    }
    let batch = (a.len() as f64 / (ask.len() as f64).sqrt()).ceil() as usize;
    let mut ans = vec![0; ask.len()];
    let mut query = vec![vec![]; a.len() / batch + 1];
    for (i, (l, r)) in ask.into_iter().enumerate() {
        query[l / batch].push((l, r, i));
    }
    let mut state = State::new(a.len());
    let mut x = 0;
    let mut y = 0;
    for (i, mut query) in query.into_iter().enumerate() {
        query.sort_by_key(|p| p.1);
        if i & 1 == 1 {
            query.reverse();
        }
        for (l, r, i) in query {
            for p in (l..x.max(l)).chain(y..y.max(r)) {
                state.insert(a[p]);
            }
            for p in (x..x.max(l)).chain(r..y.max(r)) {
                state.remove(a[p]);
            }
            x = l;
            y = r;
            ans[i] = state.solve();
        }
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}
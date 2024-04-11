//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            UF {p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                let s = x;
                x = y;
                y = s;
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            (-self.p[r]) as usize
        }
    }
}
//---------- end union_find ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        h: usize,
        w: usize,
        q: usize,
        p: [(usize1, usize1, usize); q],
    }
    let mut map = std::collections::BTreeMap::new();
    let mut state = vec![vec![(0, 0); w]; h];// 
    for (i, &(x, y, c)) in p.iter().enumerate() {
        if state[x][y].0 == c {
            continue;
        }
        map.entry(state[x][y].0).or_insert(vec![]).push((x, y, state[x][y].1, i + 1));
        state[x][y] = (c, i + 1);
    }
    for (x, state) in state.iter().enumerate() {
        for (y, &(c, t)) in state.iter().enumerate() {
            map.entry(c).or_insert(vec![]).push((x, y, t, q + 1));
        }
    }
    let mut diff = vec![0; q + 2];
    let mut index = vec![vec![0usize; w]; h];
    let mut elem = vec![vec![false; w]; h];
    for (_, p) in map.into_iter() {
        let mut z = vec![];
        let mut s = vec![];
        let mut e = vec![];
        for (x, y, a, b) in p.into_iter() {
            z.push((x, y));
            elem[x][y] = true;
            s.push((x, y, a));
            e.push((x, y, b));
        }
        z.sort();
        let mut id = 0;
        for &(x, y) in z.iter() {
            index[x][y] = id;
            id += 1;
        }
        s.sort_by_key(|p| p.2);
        e.sort_by_key(|p| p.2);
        let mut used = vec![false; z.len()];
        let mut u = union_find::UF::new(z.len());
        let mut cnt = 0i32;
        for (x, y, s) in s {
            let prev = cnt;
            cnt += 1;
            let a = index[x][y];
            used[a] = true;
            for &(p, q) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if !(p < h && q < w && elem[p][q]) {
                    continue;
                }
                let b = index[p][q];
                if used[b] && u.unite(a, b).is_some() {
                    cnt -= 1;
                }
            }
            diff[s] += cnt - prev;
        }
        let mut used = vec![false; z.len()];
        let mut u = union_find::UF::new(z.len());
        let mut cnt = 0i32;
        for &(x, y, t) in e.iter().rev() {
            let prev = cnt;
            cnt += 1;
            let a = index[x][y];
            used[a] = true;
            for &(p, q) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if !(p < h && q < w && elem[p][q]) {
                    continue;
                }
                let b = index[p][q];
                if used[b] && u.unite(a, b).is_some() {
                    cnt -= 1;
                }
            }
            diff[t] += prev - cnt;
        }
        for (x, y) in z {
            elem[x][y] = false;
        }
    }
    for i in 1..=(q + 1) {
        diff[i] += diff[i - 1];
    }
    for &a in diff[1..=q].iter() {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
// ---------- begin init array ----------
// 
// 
// new(size, zero): zerosize
// init(&mut self): 
// init_with(&mut self, f): zero f
// indexMut 
// 
//
// 
// 1. deref  data
//    derefmut 
// 2. 
//    
#[derive(Clone)]
pub struct InitArray<T> {
    data: Vec<T>,
    used: Vec<bool>,
    list: Vec<u32>,
    zero: T,
}

impl<T: Copy> InitArray<T> {
    pub fn new(zero: T, size: usize) -> Self {
        InitArray {
            data: vec![zero; size],
            used: vec![false; size],
            list: vec![],
            zero: zero,
        }
    }
    pub fn init(&mut self) {
        self.init_with(|_, _| ());
    }
    pub fn init_with<F>(&mut self, mut f: F)
    where
        F: FnMut(usize, T),
    {
        for x in self.list.drain(..) {
            let x = x as usize;
            self.used[x] = false;
            let v = std::mem::replace(&mut self.data[x], self.zero);
            f(x, v);
        }
    }
}

impl<T> std::ops::Index<usize> for InitArray<T> {
    type Output = T;
    fn index(&self, pos: usize) -> &Self::Output {
        &self.data[pos]
    }
}

impl<T> std::ops::IndexMut<usize> for InitArray<T> {
    fn index_mut(&mut self, pos: usize) -> &mut Self::Output {
        if !self.used[pos] {
            self.used[pos] = true;
            self.list.push(pos as u32);
        }
        &mut self.data[pos]
    }
}
// ---------- end init array ----------
//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&mut self, mut x: usize) -> usize {
        assert!(x < self.p.len());
        while self.p[x] >= 0 {
            let p = self.p[x] as usize;
            let q = self.p[p];
            if q >= 0 {
                self.p[x] = q;
            }
            x = p;
        }
        x
    }
    pub fn same(&mut self, x: usize, y: usize) -> bool {
        assert!(x < self.p.len() && y < self.p.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.p.len() && y < self.p.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            return None;
        }
        if self.p[x] > self.p[y] {
            std::mem::swap(&mut x, &mut y);
        }
        self.p[x] += self.p[y];
        self.p[y] = x as i32;
        Some((x, y))
    }
    pub fn size(&mut self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------

fn read() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s
}

fn run() {
    let (h, w) = {
        let s = read();
        let mut it = s.trim().split_whitespace();
        let h: usize = it.next().unwrap().parse().unwrap();
        let w: usize = it.next().unwrap().parse().unwrap();
        (h, w)
    };
    let parse = |s: String| -> Vec<bool> {
        let mut res = vec![false; w];
        for (res, s) in res.chunks_exact_mut(4).zip(s.chars()) {
            let v = s.to_digit(16).unwrap();
            for (i, res) in res.iter_mut().enumerate() {
                *res = (v >> (3 - i)) & 1 == 1;
            }
        }
        res
    };
    let mut ans = 0;
    let mut dsu = DSU::new(2 * w);
    let mut t = vec![false; w];
    let mut con = vec![];
    let mut last = InitArray::new(None, 2 * w);
    for _ in 0..h {
        for (i, t) in t.iter().enumerate() {
            if *t {
                con.push((dsu.root(w + i), i));
            }
        }
        dsu.init();
        for (v, x) in con.drain(..) {
            if let Some(y) = last[v] {
                dsu.unite(x, y);
            }
            last[v] = Some(x);
        }
        last.init();
        let s = parse(read());
        for (i, (&s, t)) in s.iter().zip(t).enumerate() {
            if s {
                ans += 1;
            }
            if s && t && dsu.unite(i, i + w).is_some() {
                ans -= 1;
            }
        }
        for (i, s) in s.windows(2).enumerate() {
            if s[0] && s[1] && dsu.unite(i + w, i + 1 + w).is_some() {
                ans -= 1;
            }
        }
        t = s;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
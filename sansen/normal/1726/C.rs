use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, s) in ask {
        let mut dsu = DSU::new(2 * n);
        let mut v = vec![None; 2 * n + 1];
        let mut pos = 0;
        for (i, s) in s.iter().enumerate() {
            if *s == b'(' {
                if let Some(u) = v[pos] {
                    dsu.unite(u, i);
                }
                v[pos] = Some(i);
                pos += 1;
            } else {
                v[pos] = None;
                pos -= 1;
                dsu.unite(v[pos].unwrap(), i);
                v[pos] = Some(i);
            }
        }
        let ans = (0..(2 * n)).filter(|v| *v == dsu.root(*v)).count();
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------
//---------- begin union_find ----------
pub struct DSU {
    p: Vec<i32>,
}
impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::i32::MAX as usize);
        DSU { p: vec![-1; n] }
    }
    pub fn init(&mut self) {
        self.p.iter_mut().for_each(|p| *p = -1);
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.p.len());
        while self.p[x] >= 0 {
            x = self.p[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
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
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.p.len());
        let p = self.p[x];
        if p >= 0 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn sum<F>(&self, mut x: usize, mut f: F) -> usize
    where
        F: FnMut(usize),
    {
        while let Some(p) = self.parent(x) {
            f(x);
            x = p;
        }
        x
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.p.len());
        let r = self.root(x);
        (-self.p[r]) as usize
    }
}
//---------- end union_find ----------
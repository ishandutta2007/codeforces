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
    where F: FnMut(usize),
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
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
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

use std::io::Write;

// d = 1
// 1
// ...
// k * (n - k) 
//
// 
//
// k, d k
// 1(0)
// 
// 
// 
// 

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        s: bytes,
        q: usize,
        ask: [(usize, usize); q],
    }
    let n = s.len();
    let mut s = s;
    for (k, d) in ask {
        let mut b = vec![vec![]; d];
        for i in 0..k {
            b[i % d].push(i);
        }
        let mut p = vec![0; k];
        let mut x = 0;
        for b in b {
            for b in b {
                p[b] = x;
                x += 1;
            }
        }
        let one = p;
        let mut p = one.clone();
        for (_i, p) in p.iter_mut().enumerate() {
            if *p > 0 {
                *p -= 1;
            }
        }
        let mut w = 0;
        while (1 << w) <= n {
            w += 1;
        }
        let w = w;
        let mut table = vec![];
        for _ in 0..w {
            let mut np = vec![0; n];
            for (np, a) in np.iter_mut().zip(p.iter()) {
                *np = p[*a];
            }
            table.push(p);
            p = np;
        }
        let mut next = vec![b'.'; n];
        for (i, &c) in s.iter().enumerate() {
            let cnt = (n - k + 1).min(n - i);
            let mut used = 0;
            let mut pos = i.min(k - 1);
            for (x, table) in table.iter().enumerate().rev() {
                if used + (1 << x) < cnt && table[pos] > 0 {
                    used += 1 << x;
                    pos = table[pos];
                }
            }
            let pos = one[pos];
            if cnt == used + 1 {
                next[n - k + pos] = c;
            } else {
                let l = i.saturating_sub(k - 1);
                next[l + used + pos] = c;
            }
        }
        s = next;
        let mut ans = String::new();
        for s in s.iter() {
            ans.push(*s as char);
        }
        writeln!(out, "{}", ans).ok();
    }
}

#[allow(dead_code)]
fn test() {
    let n = 9;
    for d in 2..n {
        for k in (d + 1)..=n {
            let mut a = (0..n).collect::<Vec<_>>();
            for i in 0..=(n - k) {
                let mut b = vec![vec![]; d];
                for (i, v) in a[i..(i + k)].iter().enumerate() {
                    b[i % d].push(*v);
                }
                let mut x = i;
                for b in b {
                    for b in b {
                        a[x] = b;
                        x += 1;
                    }
                }
            }
            println!("(d, k) = ({:2}, {:2}), {:?}", d, k, a);
        }
    }
}

fn main() {
    run();
}
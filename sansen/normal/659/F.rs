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

fn run() {
    input! {
        h: usize,
        w: usize,
        k: u64,
        a: [[u64; w]; h],
    }
    let mut b = vec![];
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            b.push((*a, i, j));
        }
    }
    b.sort();
    let mut dsu = DSU::new(h * w);
    for i in 1..=(h * w) {
        let i = i as u64;
        if k % i != 0 {
            continue;
        }
        let q = k / i;
        let mut max = (0, 0);
        while b.last().map_or(false, |p| p.0 >= q) {
            let (v, x, y) = b.pop().unwrap();
            let elem = v == q;
            if elem {
                max = (1, x * w + y).max(max);
            }
            for &(i, j) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if i < h && j < w && a[i][j] >= q {
                    dsu.unite(i * w + j, x * w + y);
                    if elem {
                        max = (dsu.size(x * w + y), x * w + y).max(max);
                    }
                }
            }
        }
        if max.0 >= i as usize {
            let len = i as usize;
            let mut ans = vec![vec![0; w]; h];
            ans[max.1 / w][max.1 % w] = q;
            let mut topo = vec![max.1];
            for i in 0..len {
                let v = topo[i];
                let (x, y) = (v / w, v % w);
                for &(i, j) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                    if i < h && j < w && dsu.same(v, i * w + j) && ans[i][j] == 0 && topo.len() < len {
                        ans[i][j] = q;
                        topo.push(i * w + j);
                    }
                }
            }
            let mut s = String::new();
            for a in ans {
                for a in a {
                    s.push_str(&format!("{} ", a));
                }
                s.pop();
                s.push('\n');
            }
            print!("YES\n{}", s);
            return;
        }
    }
    println!("NO");
}

fn main() {
    run();
}
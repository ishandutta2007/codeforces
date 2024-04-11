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

const K: usize = 2;

#[derive(Clone, Default, Debug)]
pub struct TopK<T> {
    data: [T; K],
}

impl<T: Copy + Ord + Default> TopK<T> {
    pub fn new(a: &[T; K]) -> Self {
        let mut data = *a;
        data.sort();
        data.reverse();
        Self { data: data }
    }
    pub fn merge(&self, rhs: &Self) -> Self {
        let mut res = [T::default(); K];
        let mut x = 0;
        let mut y = 0;
        for res in res.iter_mut() {
            *res = if self.data[x] > rhs.data[y] {
                x += 1;
                self.data[x - 1]
            } else {
                y += 1;
                rhs.data[y - 1]
            };
        }
        Self { data: res }
    }
}

fn run() {
    input! {
        n: usize,
        e: [(i32, i32); n],
    }
    let mut z = Vec::with_capacity(2 * n);
    z.extend(e.iter().map(|e| e.0));
    z.extend(e.iter().map(|e| e.1));
    z.sort_unstable();
    z.dedup();
    let mut dsu = DSU::new(z.len());
    let mut cnt = vec![0; z.len()];
    let mut top2 = vec![TopK::default(); z.len()];
    for (z, top2) in z.iter().zip(&mut top2) {
        top2.data[0] = *z;
    }
    for (a, b) in e {
        let a = z.binary_search(&a).unwrap();
        let b = z.binary_search(&b).unwrap();
        if let Some((a, b)) = dsu.unite(a, b) {
            cnt[a] += cnt[b];
            top2[a] = top2[a].merge(&top2[b]);
        }
        cnt[dsu.root(a)] += 1;
    }
    let mut ans = -1;
    for (i, (cnt, top2)) in cnt.iter().zip(top2).enumerate() {
        if i != dsu.root(i) {
            continue;
        }
        if dsu.size(i) < *cnt {
            ans = -1;
            break;
        }
        if dsu.size(i) == *cnt {
            ans = ans.max(top2.data[0]);
        } else {
            ans = ans.max(top2.data[1]);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
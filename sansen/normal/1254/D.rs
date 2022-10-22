// ---------- begin ModInt ----------
const MOD: u32 = 998_244_353;

#[derive(Clone, Copy)]
pub struct ModInt(u32);

impl std::ops::Add for ModInt {
    type Output = ModInt;
    fn add(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::AddAssign for ModInt {
    fn add_assign(&mut self, rhs: ModInt) {
        *self = *self + rhs;
    }
}

impl std::ops::Sub for ModInt {
    type Output = ModInt;
    fn sub(self, rhs: ModInt) -> Self::Output {
        let mut d = self.0 + MOD - rhs.0;
        if d >= MOD {
            d -= MOD;
        }
        ModInt(d)
    }
}

impl std::ops::SubAssign for ModInt {
    fn sub_assign(&mut self, rhs: ModInt) {
        *self = *self - rhs;
    }
}

impl std::ops::Mul for ModInt {
    type Output = ModInt;
    fn mul(self, rhs: ModInt) -> Self::Output {
        ModInt((self.0 as u64 * rhs.0 as u64 % MOD as u64) as u32)
    }
}

impl std::ops::MulAssign for ModInt {
    fn mul_assign(&mut self, rhs: ModInt) {
        *self = *self * rhs;
    }
}

impl std::ops::Neg for ModInt {
    type Output = ModInt;
    fn neg(self) -> Self::Output {
        ModInt(if self.0 == 0 {0} else {MOD - self.0})
    }
}

impl std::fmt::Display for ModInt {
    fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
        write!(f, "{}", self.0)
    }
}

#[allow(dead_code)]
impl ModInt {
    pub fn new(n: u32) -> ModInt {
        ModInt(n % MOD)
    }
    pub fn zero() -> ModInt {
        ModInt(0)
    }
    pub fn one() -> ModInt {
        ModInt(1)
    }
    pub fn pow(self, mut n: u32) -> ModInt {
        let mut t = ModInt::one();
        let mut s = self;
        while n > 0 {
            if n & 1 == 1 {
                t *= s;
            }
            s *= s;
            n >>= 1;
        }
        t
    }
    pub fn inv(self) -> ModInt {
        self.pow(MOD - 2)
    }
}
// ---------- end ModInt ----------
// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    graph: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

#[allow(dead_code)]
impl HLD {
    fn new(n: usize) -> Self {
        HLD {
            graph: vec![vec![]; n],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let mut q = vec![];
        let mut stack = vec![(root, root)];
        let graph = &mut self.graph;
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            for i in 0..graph[v].len() {
                if graph[v][i] == p {
                    graph[v].swap_remove(i);
                    break;
                }
            }
            for &u in &graph[v] {
                stack.push((u, v));
            }
        }
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            for i in 0..graph[v].len() {
                let u = graph[v][i];
                size[v] += size[u];
                if size[u] > size[graph[v][0]] {
                    graph[v].swap(0, i);
                }
            }
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, 0)];
        let mut k = 0;
        while let Some((v, op)) = stack.pop() {
            if op == 1 {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, 1));
            for i in 1..graph[v].len() {
                let u = graph[v][i];
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, 0));
            }
            if graph[v].len() > 0 {
                let u = graph[v][0];
                path_root[u] = path_root[v];
                path_parent[u] = path_parent[v];
                stack.push((u, 0));
            }
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    fn path(&self, v: usize, u: usize) -> Vec<(usize, usize)> {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        let mut ans = vec![];
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                ans.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                ans.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        ans.push((std::cmp::min(index[x], index[y]), std::cmp::max(index[x], index[y]) + 1));
        ans
    }
}
// ---------- end Heavy-Light decomposition ----------
//---------- begin SegmentTree Range update Point query ----------
#[allow(dead_code)]
mod segment_tree {
    pub struct RUPQ<T, F> {
        n: usize,
        b: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    impl<T: Copy, F: Fn(T, T) -> T> RUPQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> RUPQ<T, F> {
            let mut k = 0;
            while (1 << k) < n {
                k += 1;
            }
            RUPQ {
                n: 1 << k,
                b: k,
                a: vec![id; 2 << k],
                id: id,
                op: op,
            }
        }
        fn down(&mut self, x: usize) {
            let k = x + self.n;
            let a = &mut self.a;
            for i in (1..(self.b + 1)).rev() {
                let y = k >> i;
                a[2 * y] = (self.op)(a[2 * y], a[y]);
                a[2 * y + 1] = (self.op)(a[2 * y + 1], a[y]);
                a[y] = self.id;
            }
        }
        pub fn update(&mut self, mut l: usize, mut r: usize, v: T) {
//            self.down(l);
//            self.down(r - 1);
            l += self.n;
            r += self.n;
            let a = &mut self.a;
            while l < r {
                if (l & 1) == 1 {
                    a[l] = (self.op)(a[l], v);
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    a[r] = (self.op)(a[r], v);
                }
                l >>= 1;
                r >>= 1;
            }
        }
        pub fn find(&mut self, mut x: usize) -> T {
            x += self.n;
            let mut y = self.a[x];
            x >>= 1;
            while x > 0 {
                y = (self.op)(y, self.a[x]);
                x >>= 1;
            }
            y
        }
    }
}
//---------- end SegmentTree Range update Point query ----------
//---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
//---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let n: usize = sc.next();
    let q: usize = sc.next();
    let mut hld = HLD::new(n);
    for _ in 1..n {
        let a = sc.next::<usize>() - 1;
        let b = sc.next::<usize>() - 1;
        hld.add_edge(a, b);
    }
    hld.build(0);
    let mut p = vec![0; n];
    for v in 0..n {
        let l = hld.sub_tree(v).0;
        p[l] = v;
    }
    let mut sum = vec![ModInt::zero(); n];
    let mut seg = segment_tree::RUPQ::new(n, ModInt::zero(), |a, b| a + b);
    let inv = ModInt(n as u32).inv();
    for _ in 0..q {
        let op: u8 = sc.next();
        let v: usize = sc.next::<usize>() - 1;
        if op == 1 {
            let d = ModInt(sc.next());
            let (l, r) = hld.sub_tree(v);
            seg.update(l, l + 1, d * ModInt(n as u32));
            if v != 0 {
                let size_v = r - l;
                let val = d * ModInt(size_v as u32);
                seg.update(0, n, val);
                seg.update(l, r, -val);
            }
            sum[v] += d;
            if hld.graph[v].len() > 0 {
                let u = hld.graph[v][0];
                let (l, r) = hld.sub_tree(u);
                seg.update(l, r, d * ModInt((n - (r - l)) as u32));
            }
        } else {
            let mut ans = seg.find(hld.sub_tree(v).0);
            let mut path = hld.path(0, v);
            path.pop();
            for (l, _) in path {
                let v = p[l];
                let u = hld.path_parent[v];
                let size = {
                    let (l, r) = hld.sub_tree(v);
                    r - l
                };
                ans += sum[u] * ModInt((n - size) as u32);
            }
            ans *= inv;
            writeln!(out, "{}", ans).ok();
        }
    }
}
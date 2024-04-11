// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    size: usize,
    root: usize,
    edge: Vec<(usize, usize)>,
    child: Vec<Vec<usize>>,
    parent: Vec<usize>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

#[allow(dead_code)]
impl HLD {
    fn new(size: usize) -> Self {
        HLD {
            size: size,
            root: size,
            edge: Vec::with_capacity(size - 1),
            child: vec![],
            parent: vec![],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size && b < self.size && a != b);
        self.edge.push((a, b));
    }
    fn build(&mut self, root: usize) {
        assert!(root < self.size);
        self.root = root;
        let n = self.size;
        let mut deg = vec![0; n];
        for &(a, b) in self.edge.iter() {
            deg[a] += 1;
            deg[b] += 1;
        }
        let mut graph = deg.into_iter().map(|d| Vec::with_capacity(d)).collect::<Vec<_>>();
        for &(a, b) in self.edge.iter() {
            graph[a].push(b);
            graph[b].push(a);
        }
        let mut parent = vec![root; n];
        let mut q = Vec::with_capacity(n);
        q.push(root);
        for i in 0..n {
            let v = q[i];
            let child = &mut graph[v];
            if let Some(k) = child.iter().position(|u| *u == parent[v]) {
                child.swap_remove(k);
            }
            for &u in child.iter() {
                parent[u] = v;
                q.push(u);
            }
        }
        assert!(q.len() == n);
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            let child = &mut graph[v];
            if child.is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in child.iter().enumerate() {
                size[v] += size[u];
                max = std::cmp::max(max, (size[u], i));
            }
            child.swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, false)];
        let mut k = 0;
        while let Some((v, end)) = stack.pop() {
            if end {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, true));
            let child = &graph[v];
            if child.is_empty() {
                continue;
            }
            for &u in child.iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, false));
            }
            let u = child[0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push((u, false));
        }
        self.child = graph;
        self.parent = parent;
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    // u -> vpath
    fn path(&self, v: usize, u: usize, up: &mut Vec<(usize, usize)>, down: &mut Vec<(usize, usize)>) {
        up.clear();
        down.clear();
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                down.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                up.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        if index[x] < index[y] {
            down.push((index[x], index[y] + 1));
        } else {
            up.push((index[y], index[x] + 1));
        }
        down.reverse();
    }
}
// ---------- end Heavy-Light decomposition ----------
// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin ModInt ----------
mod modint {

    #[allow(dead_code)]
    pub struct Mod;
    impl ConstantModulo for Mod {
        const MOD: u32 = 1_000_000_007;
    }

    #[allow(dead_code)]
    pub struct StaticMod;
    static mut STATIC_MOD: u32 = 0;
    impl Modulo for StaticMod {
        fn modulo() -> u32 {
            unsafe { STATIC_MOD }
        }
    }

    #[allow(dead_code)]
    impl StaticMod {
        pub fn set_modulo(p: u32) {
            unsafe {
                STATIC_MOD = p;
            }
        }
    }

    use std::marker::*;
    use std::ops::*;

    pub trait Modulo {
        fn modulo() -> u32;
    }

    pub trait ConstantModulo {
        const MOD: u32;
    }

    impl<T> Modulo for T
    where
        T: ConstantModulo,
    {
        fn modulo() -> u32 {
            T::MOD
        }
    }

    pub struct ModInt<T>(pub u32, PhantomData<T>);

    impl<T> Clone for ModInt<T> {
        fn clone(&self) -> Self {
            ModInt::new_unchecked(self.0)
        }
    }

    impl<T> Copy for ModInt<T> {}

    impl<T: Modulo> Add for ModInt<T> {
        type Output = ModInt<T>;
        fn add(self, rhs: Self) -> Self::Output {
            let mut d = self.0 + rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            ModInt::new_unchecked(d)
        }
    }

    impl<T: Modulo> AddAssign for ModInt<T> {
        fn add_assign(&mut self, rhs: Self) {
            *self = *self + rhs;
        }
    }

    impl<T: Modulo> Sub for ModInt<T> {
        type Output = ModInt<T>;
        fn sub(self, rhs: Self) -> Self::Output {
            let mut d = T::modulo() + self.0 - rhs.0;
            if d >= T::modulo() {
                d -= T::modulo();
            }
            ModInt::new_unchecked(d)
        }
    }

    impl<T: Modulo> SubAssign for ModInt<T> {
        fn sub_assign(&mut self, rhs: Self) {
            *self = *self - rhs;
        }
    }

    impl<T: Modulo> Mul for ModInt<T> {
        type Output = ModInt<T>;
        fn mul(self, rhs: Self) -> Self::Output {
            let v = self.0 as u64 * rhs.0 as u64 % T::modulo() as u64;
            ModInt::new_unchecked(v as u32)
        }
    }

    impl<T: Modulo> MulAssign for ModInt<T> {
        fn mul_assign(&mut self, rhs: Self) {
            *self = *self * rhs;
        }
    }

    impl<T: Modulo> Neg for ModInt<T> {
        type Output = ModInt<T>;
        fn neg(self) -> Self::Output {
            if self.0 == 0 {
                Self::zero()
            } else {
                Self::new_unchecked(T::modulo() - self.0)
            }
        }
    }

    impl<T> std::fmt::Display for ModInt<T> {
        fn fmt<'a>(&self, f: &mut std::fmt::Formatter<'a>) -> std::fmt::Result {
            write!(f, "{}", self.0)
        }
    }

    impl<T: Modulo> std::str::FromStr for ModInt<T> {
        type Err = std::num::ParseIntError;
        fn from_str(s: &str) -> Result<Self, Self::Err> {
            let val = s.parse::<u32>()?;
            Ok(ModInt::new(val))
        }
    }

    impl<T: Modulo> From<usize> for ModInt<T> {
        fn from(val: usize) -> ModInt<T> {
            ModInt::new_unchecked((val % T::modulo() as usize) as u32)
        }
    }

    impl<T: Modulo> From<u64> for ModInt<T> {
        fn from(val: u64) -> ModInt<T> {
            ModInt::new_unchecked((val % T::modulo() as u64) as u32)
        }
    }

    impl<T: Modulo> From<i64> for ModInt<T> {
        fn from(val: i64) -> ModInt<T> {
            let m = T::modulo() as i64;
            ModInt::new((val % m + m) as u32)
        }
    }

    #[allow(dead_code)]
    impl<T> ModInt<T> {
        pub fn new_unchecked(d: u32) -> Self {
            ModInt(d, PhantomData)
        }
        pub fn zero() -> Self {
            ModInt::new_unchecked(0)
        }
        pub fn one() -> Self {
            ModInt::new_unchecked(1)
        }
        pub fn is_zero(&self) -> bool {
            self.0 == 0
        }
    }

    #[allow(dead_code)]
    impl<T: Modulo> ModInt<T> {
        pub fn new(d: u32) -> Self {
            ModInt::new_unchecked(d % T::modulo())
        }
        pub fn pow(&self, mut n: u64) -> Self {
            let mut t = Self::one();
            let mut s = *self;
            while n > 0 {
                if n & 1 == 1 {
                    t *= s;
                }
                s *= s;
                n >>= 1;
            }
            t
        }
        pub fn inv(&self) -> Self {
            assert!(self.0 != 0);
            self.pow(T::modulo() as u64 - 2)
        }
    }

    #[allow(dead_code)]
    pub fn mod_pow(r: u64, mut n: u64, m: u64) -> u64 {
        let mut t = 1 % m;
        let mut s = r % m;
        while n > 0 {
            if n & 1 == 1 {
                t = t * s % m;
            }
            s = s * s % m;
            n >>= 1;
        }
        t
    }
}
// ---------- end ModInt ----------
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

//

use std::collections::*;
use std::io::Write;

use modint::*;

type M = ModInt<Mod>;

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
        a: [usize; n],
        q: usize,
        ask: [(usize1, usize1, usize); q],
    }
    let mut hld = HLD::new(n);
    for (a, b) in e {
        hld.add_edge(a, b);
    }
    hld.build(0);
    let m = 10_000_000;
    let mut factor: Vec<usize> = (0..=m).collect();
    for i in (2..).take_while(|p| p * p <= m) {
        if factor[i] == i {
            for j in i..=(m / i) {
                factor[j * i] = i;
            }
        }
    }
    let mut map = BTreeMap::new();
    for (i, a) in a.iter().enumerate() {
        let mut x = *a;
        while x > 1 {
            let p = factor[x];
            map.entry(p).or_insert(vec![]).push(i);
            while x % p == 0 {
                x /= p;
            }
        }
    }
    let mut query = BTreeMap::new();
    for (i, &(_, _, x)) in ask.iter().enumerate() {
        let mut x = x;
        while x > 1 {
            let p = factor[x];
            query.entry(p).or_insert(vec![]).push(i);
            while x % p == 0 {
                x /= p;
            }
        }
    }
    let mut z = vec![];
    for p in map.keys().chain(query.keys()) {
        z.push(*p);
    }
    z.sort();
    z.dedup();
    let mut calc = vec![(vec![], vec![]); z.len()];
    for (p, a) in map {
        let k = z.binary_search(&p).unwrap();
        calc[k].0 = a;
    }
    for (p, a) in query {
        let k = z.binary_search(&p).unwrap();
        calc[k].1 = a;
    }
    let mut seg = segment_tree::PURQ::new(n, M::one(), |a, b| a * b);
    let mut ans = vec![M::one(); q];
    let mut up = vec![];
    let mut down = vec![];
    for (&p, (index, query)) in z.iter().zip(calc.into_iter()) {
        if index.is_empty()|| query.is_empty() {
            continue;
        }
        let mut event = vec![];
        for k in index {
            let mut x = a[k];
            for i in 1.. {
                if x % p != 0 {
                    break;
                }
                x /= p;
                event.push((i, 0, k));
            }
        }
        for k in query {
            let mut x = ask[k].2;
            for i in 0.. {
                if x % p != 0 {
                    event.push((i, 1, k));
                    break;
                } else {
                    x /= p;
                }
            }
        }
        event.sort();
        let p = M::from(p);
        let inv = p.inv();
        for &(_, op, k) in event.iter() {
            if op == 0 {
                let x = hld.sub_tree(k).0;
                let v = seg.find(x, x + 1);
                seg.update(x, v * p);
            } else {
                let (a, b, _) = ask[k];
                hld.path(a, b, &mut up, &mut down);
                for &(l, r) in up.iter().chain(down.iter()) {
                    ans[k] *= seg.find(l, r);
                }
            }
        }
        for &(_, op, k) in event.iter() {
            if op == 0 {
                let x = hld.sub_tree(k).0;
                let v = seg.find(x, x + 1);
                seg.update(x, v * inv);
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
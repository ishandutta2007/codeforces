// ---------- begin CSR ----------
pub struct CSR<T> {
    size: usize,
    pos: Vec<u32>,
    list: Vec<(u32, T)>,
}

impl<T> CSR<T>
where
    T: Default + Copy,
{
    pub fn new<I>(size: usize, it: I) -> Self
    where
        I: Iterator<Item = (usize, usize, T)> + Clone,
    {
        let mut pos = vec![0; size + 1];
        for (s, t, _) in it.clone() {
            assert!(s < size && t < size);
            pos[s + 1] += 1;
        }
        for i in 1..=size {
            pos[i] += pos[i - 1];
        }
        let mut x = pos[..size].to_vec();
        let mut list = vec![(0, T::default()); pos[size] as usize];
        for (s, t, w) in it {
            let x = &mut x[s];
            list[*x as usize] = (t as u32, w);
            *x += 1;
        }
        CSR { size, pos, list }
    }
    pub fn list(&self, v: usize) -> impl Iterator<Item = (usize, T)> + '_ {
        assert!(v < self.size);
        let s = self.pos[v] as usize;
        let t = self.pos[v + 1] as usize;
        self.list[s..t].iter().map(|p| (p.0 as usize, p.1))
    }
}
// ---------- end CSR ----------
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

struct Solver {
    add: i32,
    dp: Vec<(i32, i32)>,
    ans: i64,
}

impl Solver {
    fn new(n: usize) -> Self {
        Self {
            add: 0,
            dp: vec![(0, 0); n],
            ans: 0,
        }
    }
    fn find(&self, x: usize) -> (i32, i32) {
        let dp = self.dp[x];
        (dp.0 + self.add, dp.1)
    }
    fn increment(&mut self) {
        self.add += 1;
    }
    fn set_at(&mut self, x: usize, p: (i32, i32)) {
        self.dp[x] = (p.0 - self.add, p.1)
    }
}

fn dfs(v: usize, p: usize, g: &CSR<u32>, solver: &mut Solver) {
    solver.increment();
    for (u, c) in g.list(v).filter(|e| e.0 != p) {
        let c = c as usize;
        let save = solver.find(c);
        solver.set_at(c, (0, 0));
        dfs(u, v, g, solver);
        let (a, b) = solver.find(c);
        solver.ans += a as i64 * b as i64;
        solver.set_at(c, (save.0, save.1 + a));
    }
}

fn main() {
    input! {
        n: usize,
        e: [(u32, u32, u32); n - 1],
    }
    let g = CSR::new(n, e.iter().flat_map(|e| {
        let (a, b, c) = (e.0 as usize - 1, e.1 as usize - 1, e.2 - 1);
        [(a, b, c), (b, a, c)]
    }));
    let mut solver = Solver::new(n);
    dfs(0, n, &g, &mut solver);
    let mut ans = solver.ans;
    for i in 0..n {
        let (a, b) = solver.find(i);
        ans += a as i64 * b as i64;
    }
    println!("{}", ans);
}
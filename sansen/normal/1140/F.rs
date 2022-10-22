use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let m = 300000;
    let mut map = Map::new();
    let mut event = vec![vec![]; q];
    for (i, &(x, y)) in ask.iter().enumerate() {
        let y = y + m;
        if let Some(s) = map.insert((x, y), i) {
            event[s].push((x, y, i));
            map.remove(&(x, y));
        }
    }
    for ((x, y), s) in map {
        event[s].push((x, y, q));
    }
    let func = |w: usize| -> usize {
        if w.count_ones() == 1 {
            w
        } else {
            (w / 2 + 1).next_power_of_two()
        }
    };
    let mut state = State::new();
    let mut cnt = vec![0; q];
    let mut memo = vec![vec![]; (q + 1).next_power_of_two().trailing_zeros() as usize];
    use util::*;
    let ans = (0..q)
        .map(|s| {
            for (x, y, t) in std::mem::take(&mut event[s]) {
                let mut w = func(t - s);
                if s > 0 {
                    w = w.min(1 << s.trailing_zeros());
                }
                if s + w < t {
                    event[s + w].push((x, y, t));
                }
                cnt[s + w - 1] += 1;
                memo[w.trailing_zeros() as usize].push((x, y));
            }
            for (x, y) in memo.iter_mut().rev().flat_map(|memo| memo.drain(..)) {
                state.unite(x, y);
            }
            let save = state.ans();
            for _ in 0..cnt[s] {
                state.undo();
            }
            save
        })
        .join(" ");
    println!("{}", ans);
}

struct State {
    u: DSU,
    dp: Vec<(u64, u64)>,
    sum: u64,
}

impl State {
    fn new() -> Self {
        let w = 300_000;
        State {
            u: DSU::new(2 * w),
            dp: (0..w).map(|_| (1, 0)).chain((0..w).map(|_| (0, 1))).collect(),
            sum: 0,
        }
    }
    fn unite(&mut self, a: usize, b: usize) {
        if let Some((a, b)) = self.u.unite(a, b) {
            let (x, y) = self.dp[a];
            let (p, q) = self.dp[b];
            self.sum += x * q + p * y;
            self.dp[a] = (x + p, y + q);
        }
    }
    fn undo(&mut self) {
        if let Some((a, b)) = self.u.undo() {
            let (p, q) = self.dp[b];
            self.dp[a].0 -= p;
            self.dp[a].1 -= q;
            let (x, y) = self.dp[a];
            self.sum -= x * q + p * y;
        }
    }
    fn ans(&self) -> u64 {
        self.sum
    }
}

fn main() {
    run();
}

//---------- begin union_find ----------
pub struct DSU {
    parent: Vec<u32>,
    size: Vec<u32>,
    stack: Vec<Option<(u32, u32)>>,
}

impl DSU {
    pub fn new(n: usize) -> DSU {
        assert!(n < std::u32::MAX as usize);
        let mut res = DSU {
            parent: vec![0; n],
            size: vec![1; n],
            stack: vec![],
        };
        res.init();
        res
    }
    pub fn init(&mut self) {
        self.stack.clear();
        for (i, (parent, size)) in self.parent.iter_mut().zip(self.size.iter_mut()).enumerate() {
            *parent = i as u32;
            *size = 1;
        }
    }
    pub fn root(&self, mut x: usize) -> usize {
        assert!(x < self.parent.len());
        while self.parent[x] != x as u32 {
            x = self.parent[x] as usize;
        }
        x
    }
    pub fn same(&self, x: usize, y: usize) -> bool {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        self.root(x) == self.root(y)
    }
    pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
        assert!(x < self.parent.len());
        assert!(y < self.parent.len());
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y {
            self.stack.push(None);
            return None;
        }
        if (self.size[x], x) < (self.size[y], y) {
            std::mem::swap(&mut x, &mut y);
        }
        self.size[x] += self.size[y];
        self.parent[y] = x as u32;
        self.stack.push(Some((x as u32, y as u32)));
        Some((x, y))
    }
    pub fn parent(&self, x: usize) -> Option<usize> {
        assert!(x < self.parent.len());
        let p = self.parent[x];
        if p != x as u32 {
            Some(p as usize)
        } else {
            None
        }
    }
    pub fn size(&self, x: usize) -> usize {
        assert!(x < self.parent.len());
        let r = self.root(x);
        self.size[r] as usize
    }
    pub fn undo(&mut self) -> Option<(usize, usize)> {
        self.stack.pop().unwrap().map(|(x, y)| {
            let x = x as usize;
            let y = y as usize;
            self.size[x] -= self.size[y];
            self.parent[y] = y as u32;
            (x, y)
        })
    }
    pub fn snap(&mut self) {
        self.stack.clear();
    }
    pub fn rollback(&mut self) {
        while !self.stack.is_empty() {
            self.undo();
        }
    }
}
//---------- end union_find ----------
mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
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
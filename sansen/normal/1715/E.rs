use std::collections::*;

type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        e: [(usize1, usize1, i64); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b, w) in e {
        g[a].push((b, w));
        g[b].push((a, w));
    }
    let mut h = RadixHeap::new();
    let mut dijkstra = |dp: &mut [i64]| {
        h.init();
        for (i, dp) in dp.iter().enumerate() {
            h.push(*dp, i);
        }
        while let Some((d, v)) = h.pop() {
            if d > dp[v] {
                continue;
            }
            for &(u, w) in g[v].iter() {
                let d = d + w;
                if dp[u].chmin(d) {
                    h.push(d, u);
                }
            }
        }
    };
    let inf = 10i64.pow(10);
    let mut dp = vec![inf; n];
    dp[0] = 0;
    dijkstra(&mut dp);
    for _ in 0..k {
        let mut deq = Deque::new();
        for (i, dp) in dp.iter().enumerate() {
            let i = i as i64;
            let (a, b) = (-2 * i, *dp + i * i);
            while deq.len() > 1 {
                let len = deq.len();
                let (c, d) = deq[len - 1];
                let (e, f) = deq[len - 2];
                if (b - d) * (e - a) <= (b - f) * (c - a) {
                    deq.pop_back();
                } else {
                    break;
                }
            }
            deq.push_back((a, b));
        }
        for (i, dp) in dp.iter_mut().enumerate() {
            let i = i as i64;
            while deq.len() > 1 {
                let (a, b) = deq[0];
                let (c, d) = deq[1];
                if a * i + b >= c * i + d {
                    deq.pop_front();
                } else {
                    break;
                }
            }
            *dp = deq.get(0).map(|p| p.0 * i + p.1 + i * i).unwrap();
        }
        dijkstra(&mut dp);
    }
    use util::*;
    println!("{}", dp.iter().join(" "));
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
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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

// ---------- begin radix heap ----------
pub trait RadixKeyType: Copy + Ord + std::ops::BitXor<Output = Self> {
    fn leading_zeros(self) -> usize;
    fn zero() -> Self;
    const SIZE: usize = std::mem::size_of::<Self>() * 8;
    fn bsr(self) -> usize {
        Self::SIZE - self.leading_zeros() as usize
    }
}

pub struct RadixHeap<K, V> {
    buf: Vec<Vec<(K, V)>>,
    last: K,
}

impl<K, V> RadixHeap<K, V>
where
    K: RadixKeyType,
{
    pub fn new() -> Self {
        RadixHeap {
            buf: (0..K::SIZE).map(|_| vec![]).collect(),
            last: K::zero(),
        }
    }
    pub fn init(&mut self) {
        self.buf.iter_mut().for_each(|p| p.clear());
        self.last = K::zero();
    }
    pub fn push(&mut self, key: K, val: V) {
        assert!(self.last <= key);
        self.buf[(self.last ^ key).bsr()].push((key, val));
    }
    pub fn pop(&mut self) -> Option<(K, V)> {
        if self.buf[0].is_empty() {
            if let Some(x) = self.buf.iter().position(|a| !a.is_empty()) {
                let mut a = std::mem::take(&mut self.buf[x]);
                self.last = a.iter().map(|p| p.0).min().unwrap();
                for (key, val) in a.drain(..) {
                    self.buf[(self.last ^ key).bsr()].push((key, val));
                }
                self.buf[x] = a;
            }
        }
        self.buf[0].pop()
    }
}

macro_rules! impl_radix_key_type {
    ($x: ty) => {
        impl RadixKeyType for $x {
            fn leading_zeros(self) -> usize {
                self.leading_zeros() as usize
            }
            fn zero() -> Self {
                0
            }
        }
    };
}

impl_radix_key_type!(u64);
impl_radix_key_type!(i64);
impl_radix_key_type!(u32);
impl_radix_key_type!(usize);
// ---------- end radix heap ----------
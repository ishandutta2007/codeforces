// 1 <= p_i <= k
// 1 <= n, k <= 10^5
// 1 <= a_i <= a_{i + 1} <= 10^5
// 
// 
// 

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    let ask = read();
    for (k, a) in ask {
        let n = a.len();
        let m = a[n - 1];
        let mut h = RadixHeap::new();
        let mut min = m;
        for a in a {
            h.push(!a, a);
            min.chmin(a);
        }
        let mut ans = m;
        while let Some((q, a)) = h.pop() {
            let q = !q;
            ans.chmin(q - min);
            if q == 0 {
                break;
            }
            let d = a / q + 1;
            if d > k {
                break;
            }
            let q = a / d;
            min.chmin(q);
            h.push(!q, a);
        }
        println!("{}", ans);
    }
}

fn read() -> Vec<(usize, Vec<usize>)> {
    let mut s = String::new();
    use std::io::*;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace().flat_map(|s| s.parse::<usize>());
    let mut next = || it.next().unwrap();
    let t = next();
    (0..t)
        .map(|_| {
            let n = next();
            let k = next();
            (k, (0..n).map(|_| next()).collect())
        })
        .collect()
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
            buf: (0..=K::SIZE).map(|_| vec![]).collect(),
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
impl_radix_key_type!(u32);
impl_radix_key_type!(usize);
// ---------- end radix heap ----------
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
fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}
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

use std::collections::*;
use std::hash::*;

#[derive(Clone)]
struct NaiveHasher(u64);

impl NaiveHasher {
    fn new() -> Self {
        Self(0)
    }
}

impl Hasher for NaiveHasher {
    fn finish(&self) -> u64 {
        self.0
    }
    fn write(&mut self, bytes: &[u8]) {
        for b in bytes.chunks(8) {
            for (i, b) in b.iter().enumerate() {
                self.0 ^= (*b as u64) << (8 * i);
            }
        }
    }
    fn write_usize(&mut self, x: usize) {
        self.0 ^= x as u64;
    }
}

#[derive(Default, Clone)]
struct NaiveHashBuilder;
impl BuildHasher for NaiveHashBuilder {
    type Hasher = NaiveHasher;
    fn build_hasher(&self) -> Self::Hasher {
        Self::Hasher::new()
    }
}

type Map<K, V> = HashMap<K, V, NaiveHashBuilder>;

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut a = a;
    a.iter_mut().for_each(|a| *a -= 1);
    let hash = (0..n).map(|_| [0, rand(), rand()]).collect::<Vec<_>>();
    let mut cnt = vec![0; n];
    let mut xor = vec![0; n + 1];
    for (i, &a) in a.iter().enumerate().rev() {
        let a = a as usize;
        let mut v = xor[i + 1];
        v ^= hash[a][cnt[a]];
        cnt[a] = (cnt[a] + 1) % 3;
        xor[i] = v ^ hash[a][cnt[a]];
    }
    let mut ans = 0u64;
    let mut r = n;
    let mut map = Map::default();
    map.insert(xor[n], 1);
    cnt.iter_mut().for_each(|c| *c = 0);
    for i in (0..n).rev() {
        let x = a[i] as usize;
        cnt[x] += 1;
        while cnt[x] > 3 {
            *map.get_mut(&xor[r]).unwrap() -= 1;
            r -= 1;
            cnt[a[r] as usize] -= 1;
        }
        let po = map.entry(xor[i]).or_insert(0);
        ans += *po;
        *po += 1;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
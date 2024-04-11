fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> u64 {
    static mut X: u64 = 0;
    unsafe {
        if X == 0 {
            X = rand_memory() as u64;
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

use std::io::Write;

pub struct Fenwick2D {
    bit: Vec<Vec<u64>>,
}

impl Fenwick2D {
    pub fn new(h: usize, w: usize) -> Self {
        Fenwick2D {
            bit: vec![vec![0u64; w + 1]; h + 1],
        }
    }
    pub fn add(&mut self, mut x: usize, y: usize, v: u64) {
        while let Some(bit) = self.bit.get_mut(x) {
            let mut y = y;
            while let Some(bit) = bit.get_mut(y) {
                *bit ^= v;
                y += y & (!y + 1);
            }
            x += x & (!x + 1);
        }
    }
    pub fn sum(&self, mut x: usize, y: usize) -> u64 {
        let mut res = 0;
        while x > 0 {
            let bit = &self.bit[x];
            x -= x & (!x + 1);
            let mut y = y;
            while y > 0 {
                res ^= bit[y];
                y -= y & (!y + 1);
            }
        }
        res
    }
}

fn run() {
    input! {
        h: usize,
        w: usize,
        q: usize,
        ask: [(u8, usize, usize, usize, usize); q],
    }
    let mut bit = Fenwick2D::new(h, w);
    let mut hash = std::collections::BTreeMap::<(usize, usize, usize, usize), u64>::new();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, a, b, c, d) in ask {
        if op == 3 {
            let x = bit.sum(a, b);
            let y = bit.sum(c, d);
            if x == y {
                writeln!(out, "Yes").ok();
            } else {
                writeln!(out, "No").ok();
            }
        } else {
            let hash = *hash.entry((a, b, c, d)).or_insert(rand());
            for &(x, y) in [(a, b), (a, d + 1), (c + 1, b), (c + 1, d + 1)].iter() {
                bit.add(x, y, hash);
            }
        }
    }
}

fn main() {
    run();
}
// reference: https://twitter.com/shino_skycrew/status/1322841105130422273

use std::ops::*;

#[derive(Clone, Eq, PartialEq, Ord, PartialOrd, Debug, Hash)]
pub struct UVec<T>(pub Vec<T>);

impl<T: Clone> UVec<T> {
    pub fn new(ini: T, size: usize) -> Self {
        UVec(vec![ini; size])
    }
}

impl<T> Deref for UVec<T> {
    type Target = Vec<T>;
    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

impl<T> DerefMut for UVec<T> {
    fn deref_mut(&mut self) -> &mut Self::Target {
        &mut self.0
    }
}

macro_rules! impl_index {
    ($x: ty) => {
        impl<T> Index<$x> for UVec<T> {
            type Output = T;
            fn index(&self, index: $x) -> &Self::Output {
                unsafe {self.0.get_unchecked(index as usize)}
            }
        }
        impl<T> IndexMut<$x> for UVec<T> {
            fn index_mut(&mut self, index: $x) -> &mut Self::Output {
                unsafe {self.0.get_unchecked_mut(index as usize)}
            }
        }
    }
}

impl_index!(usize);
impl_index!(u64);
impl_index!(u32);
impl_index!(u16);
impl_index!(u8);

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

fn run() {
    input! {
        n: usize,
        q: usize,
        p: [u32; n],
        ask: [(u8, u32, u32); q],
    }
    let mut p = UVec(p);
    let mut ip = UVec::new(0u32, n);
    for (i, p) in p.iter_mut().enumerate() {
        *p -= 1;
        ip[*p] = i as u32;
    }
    let step = (n as f64 / 9.0).sqrt().ceil() as u32;
    let mut memo = UVec::new(n as u32, n);
    for i in 0..n {
        if memo[i] < (n as u32) {
            continue;
        }
        let mut pos = i as u32;
        for _ in 0..step {
            pos = p[pos];
        }
        let mut x = i as u32;
        while memo[x] == (n as u32) {
            memo[x] = pos as u32;
            x = p[x];
            pos = p[pos];
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, x, y) in ask {
        if op == 1 {
            let x = x - 1;
            let y = y - 1;
            p.swap(x as usize, y as usize);
            ip[p[x]] = x;
            ip[p[y]] = y;
            for x in [x, y].iter() {
                let mut x = *x;
                let mut pos = x;
                for _ in 0..step {
                    pos = p[pos];
                }
                for _ in 0..step {
                    memo[x] = pos;
                    x = ip[x];
                    pos = ip[pos];
                }
            }
        } else {
            let k = y;
            let mut pos = x - 1;
            for _ in 0..(k / step) {
                pos = memo[pos];
            }
            for _ in 0..(k % step) {
                pos = p[pos];
            }
            writeln!(out, "{}", pos + 1).ok();
        }
    }
}

fn main() {
    run();
}
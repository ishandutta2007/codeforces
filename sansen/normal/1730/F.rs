use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        n: usize,
        k: usize,
        p: [usize1; n],
    }
    //        let mut p = (0..n).collect::<Vec<_>>();
    //        shuffle(&mut p);
    let mut ip = vec![0; n];
    for i in 0..n {
        ip[p[i]] = i;
    }
    /*
    let mut dp = Map::new();
    dp.insert((0, 0), 0);
    for t in 0..n {
        let mut next = Map::new();
        for ((s, bit), v) in dp {
            for j in 0..=k.min(n - s - 1) {
                if bit >> j & 1 == 1 {
                    continue;
                }
                let pos = ip[s + j];
                let mut s = s;
                let mut bit = bit | (1 << j);
                while bit & 1 == 1 {
                    s += 1;
                    bit >>= 1;
                }
                let v = v + p[..pos]
                    .iter()
                    .filter(|p| **p >= s && bit >> (**p - s).min(k + 1) & 1 == 0)
                    .count() as u32;
                next.entry((s, bit)).or_insert(std::u32::MAX).chmin(v);
            }
        }
        dp = next;
    }
    let correct = dp.values().min().unwrap();
    */
    let mut need = vec![0; n];
    let up = k + 1;
    for pos in 0..n {
        let v = p[pos] + up;
        need[pos] = p[..pos].iter().filter(|p| **p >= v).count() as u32;
    }
    let mut dp = Map::new();
    dp.insert((0, 0), 0);
    for _ in 0..n {
        let mut next = Map::new();
        for ((s, bit), v) in dp {
            for j in 0..=k.min(n - s - 1) {
                if bit >> j & 1 == 1 {
                    continue;
                }
                let a = s + j;
                let pos = ip[a];
                let mut s = s;
                let mut bit = bit | (1 << j);
                while bit & 1 == 1 {
                    s += 1;
                    bit >>= 1;
                }
                let mut v = v;
                v += need[pos];
                for i in s..(a + up) {
                    if i < n && bit >> (i - s) & 1 == 0 && ip[i] < pos {
                        v += 1;
                    }
                }
                next.entry((s, bit)).or_insert(std::u32::MAX).chmin(v);
            }
        }
        dp = next;
    }
    let fast = dp.values().min().unwrap();
    println!("{}", fast);
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

fn shuffle<T>(a: &mut [T]) {
    for i in 1..a.len() {
        let p = rand() % (i + 1);
        a.swap(i, p);
    }
}
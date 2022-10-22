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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn pow_mod(mut r: u64, mut n: u64, m: u64) -> u64 {
    let mut t = 1 % m;
    r %= m;
    while n > 0 {
        if n & 1 == 1 {
            t = t * r % m;
        }
        r = r * r % m;
        n >>= 1;
    }
    t
}

fn run() {
    input! {
        n: usize,
        m: usize,
        seed: u64,
        v_max: u64,
    }
    let mut seed = seed;
    let mut rnd = || -> u64 {
        let res = seed;
        seed = (seed * 7 + 13) % 1000000007;
        res
    };
    let mut set = Set::new();
    for i in 0..n {
        let a = rnd() % v_max + 1;
        set.insert((i, i + 1, a));
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for _ in 0..m {
        let op = rnd() % 4 + 1;
        let mut l = rnd() as usize % n + 1;
        let mut r = rnd() as usize % n + 1;
        if l > r {
            std::mem::swap(&mut l, &mut r);
        }
        let (l, r) = (l - 1, r);
        let mut a = vec![];
        if let Some(&p) = set.range(..((l, r, 0))).next_back() {
            let (x, y, z) = p;
            if l < y {
                set.remove(&p);
                set.insert((x, l, z));
                if y <= r {
                    a.push((l, y, z));
                } else {
                    set.insert((r, y, z));
                    a.push((l, r, z));
                }
            }
        }
        while let Some(&p) = set.range((l, 0, 0)..).next() {
            if p.0 >= r {
                break;
            }
            set.remove(&p);
            let (x, y, z) = p;
            if y <= r {
                a.push((x, y, z));
            } else {
                set.insert((r, y, z));
                a.push((x, r, z));
            }
        }
        if op == 1 {
            let x = rnd() % v_max + 1;
            a.iter_mut().for_each(|a| a.2 += x);
        } else if op == 2 {
            let x = rnd() % v_max + 1;
            a = vec![(l, r, x)];
        } else if op == 3 {
            let mut x = rnd() as usize % (r - l);
            a.sort_by_key(|p| p.2);
            for &(l, r, v) in a.iter() {
                if x < r - l {
                    writeln!(out, "{}", v).ok();
                    break;
                }
                x -= r - l;
            }
        } else {
            let x = rnd() % v_max + 1;
            let y = rnd() % v_max + 1;
            let mut ans = 0;
            for &(l, r, v) in a.iter() {
                ans += (r - l) as u64 * pow_mod(v, x, y);
            }
            ans %= y;
            writeln!(out, "{}", ans).ok();
        }
        for a in a {
            set.insert(a);
        }
    }
}

fn main() {
    run();
}
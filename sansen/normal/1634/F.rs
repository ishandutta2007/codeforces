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

fn run() {
    input! {
        n: usize,
        q: usize,
        m: u64,
        a: [u64; n],
        b: [u64; n],
        ask: [(bytes, usize1, usize); q],
    }
    let mut a = a;
    let mut b = b;
    for i in (2..n).rev() {
        a[i] = (a[i] + m + m - a[i - 1] - a[i - 2]) % m;
        b[i] = (b[i] + m + m - b[i - 1] - b[i - 2]) % m;
    }
    if n > 1 {
        a[1] = (a[1] + m - a[0]) % m;
        b[1] = (b[1] + m - b[0]) % m;
    }
    let mut fib = vec![0; n + 10];
    fib[1] = 1;
    for i in 2..fib.len() {
        fib[i] = (fib[i - 1] + fib[i - 2]) % m;
    }
    let mut cnt = a.iter().zip(b.iter()).filter(|p| *p.0 == *p.1).count();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (op, l, r) in ask {
        for &x in [l, r, r + 1].iter() {
            if x < n && a[x] == b[x] {
                cnt -= 1;
            }
        }
        let len = r - l;
        if op[0] == b'A' {
            a[l] = (a[l] + fib[1]) % m;
            if r < n {
                a[r] = (a[r] + m - fib[len + 1]) % m;
            }
            if r + 1 < n {
                a[r + 1] = (a[r + 1] + m - fib[len]) % m;
            }
        } else {
            b[l] = (b[l] + fib[1]) % m;
            if r < n {
                b[r] = (b[r] + m - fib[len + 1]) % m;
            }
            if r + 1 < n {
                b[r + 1] = (b[r + 1] + m - fib[len]) % m;
            }
        }
        for &x in [l, r, r + 1].iter() {
            if x < n && a[x] == b[x] {
                cnt += 1;
            }
        }
        if cnt == n {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}
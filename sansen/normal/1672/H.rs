use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        n: usize,
        q: usize,
        s: bytes,
        ask: [(usize1, usize); q],
    }
    let mut a = s.windows(2).map(|s| ((s[0], s[1]) == (b'0', b'0')) as usize).collect::<Vec<_>>();
    let mut b = s.windows(2).map(|s| ((s[0], s[1]) == (b'1', b'1')) as usize).collect::<Vec<_>>();
    a.push(0);
    b.push(0);
    for i in (0..(n - 1)).rev() {
        a[i] += a[i + 1];
        b[i] += b[i + 1];
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let mut ans = 1;
        ans += a[l] - a[r - 1];
        ans += b[l] - b[r - 1];
        ans -= (a[l] - a[r - 1]).min(b[l] - b[r - 1]);
        writeln!(out, "{}", ans).ok();
    }
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
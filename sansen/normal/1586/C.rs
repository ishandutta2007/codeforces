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

// 1yes
// 2
// N
// 
//

fn run() {
    input! {
        h: usize,
        w: usize,
        s: [bytes; h],
        q: usize,
        ask: [(usize1, usize); q],
    }
    let mut ban = vec![0; w + 1];
    for j in 1..w {
        for i in 1..h {
            if s[i - 1][j] == b'X' && s[i][j - 1] == b'X' {
                ban[j] = 1;
                break;
            }
        }
    }
    for j in (0..w).rev() {
        ban[j] += ban[j + 1];
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let ans = if r - l == 1 {
            "YES"
        } else if ban[l + 1] - ban[r] > 0 {
            "NO"
        } else {
            "YES"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
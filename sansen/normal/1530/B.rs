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
        t: usize,
        ask: [(usize, usize); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (h, w) in ask {
        let mut ans = vec![vec!['0'; w]; h];
        let mut pos = (0, 0);
        let mut dir = (0, 1);
        while pos != (1, 0) {
            let mut v = '1';
            for dx in [!0, 0, 1].iter() {
                for dy in [!0, 0, 1].iter() {
                    let x = pos.0 + dx;
                    let y = pos.1 + dy;
                    if x < h && y < w && ans[x][y] == '1' {
                        v = '0';
                    }
                }
            }
            ans[pos.0][pos.1] = v;
            if pos.0 + dir.0 >= h || pos.1 + dir.1 >= w {
                dir = (dir.1, !dir.0 + 1);
            }
            pos.0 += dir.0;
            pos.1 += dir.1;
        }
        for ans in ans {
            let s = ans.into_iter().collect::<String>();
            writeln!(out, "{}", s).ok();
        }
        writeln!(out).ok();
    }
}

fn main() {
    run();
}
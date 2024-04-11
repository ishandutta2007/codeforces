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
        h: usize,
        w: usize,
        q: usize,
        ask: [(usize1, usize1); q],
    }
    let count = |src: (usize, usize), mut dir: (usize, usize), block: &[Vec<bool>]| -> usize {
        let mut pos = (src.0 + dir.0, src.1 + dir.1);
        let mut ans = 0;
        while pos.0 < h && pos.1 < w && !block[pos.0][pos.1] {
            std::mem::swap(&mut dir.0, &mut dir.1);
            ans += 1;
            pos.0 += dir.0;
            pos.1 += dir.1;
        }
        ans
    };
    let mut block = vec![vec![false; w]; h];
    let mut ans = 0;
    for i in 0..h {
        for j in 0..w {
            let x = h - 1 - i;
            let y = w - 1 - j;
            ans += 1;
            ans += std::cmp::min(2 * x + 1, 2 * y);
            ans += std::cmp::min(2 * x, 2 * y + 1);
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (x, y) in ask {
        if block[x][y] {
            ans += (count((x, y), (1, 0), &block) + 1) * (count((x, y), (0, !0), &block) + 1);
            ans += (count((x, y), (0, 1), &block) + 1) * (count((x, y), (!0, 0), &block) + 1);
            ans -= 1;
        } else {
            ans -= (count((x, y), (1, 0), &block) + 1) * (count((x, y), (0, !0), &block) + 1);
            ans -= (count((x, y), (0, 1), &block) + 1) * (count((x, y), (!0, 0), &block) + 1);
            ans += 1;
        }
        block[x][y] ^= true;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
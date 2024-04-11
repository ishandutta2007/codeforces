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

type Set<T> = std::collections::BTreeSet<T>;

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize, usize); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (h, w, k) in ask {
        let b = k;
        let a = h * w / 2 - b;
        let ans = match (h % 2, w % 2, a % 2, b % 2) {
            (0, 0, 0, 0) => "YES",
            (0, 0, _, _) => "NO",
            (0, 1, _, 0) if b <= (w - 1) * h / 2 => "YES",
            (0, 1, _, _) => "NO",
            (1, 0, 0, _) if a <= (h - 1) * w / 2 => "YES",
            _ => "NO",
        };
        writeln!(out, "{}", ans).ok();
        if ans == "NO" {
            continue;
        }
        let op = "qwertyuiasdfghjkzxcvbnm".chars().collect::<Vec<_>>();
        let mut ans = vec![vec!['.'; w + 2]; h + 2];
        let mut a = a;
        let mut b = b;
        if h % 2 == 1 {
            for j in (1..=w).step_by(2) {
                let c = op[(j / 2) % 2];
                ans[h][j] = c;
                ans[h][j + 1] = c;
                b -= 1;
            }
        } else if w % 2 == 1 {
            for j in (1..=h).step_by(2) {
                let c = op[(j / 2) % 2];
                ans[j][w] = c;
                ans[j + 1][w] = c;
                a -= 1;
            }
        }
        for i in (1..h).step_by(2) {
            for j in (1..w).step_by(2) {
                if a > 0 {
                    for k in 0..2 {
                        let mut set = Set::new();
                        set.insert(ans[i - 1][j + k]);
                        set.insert(ans[i][j + k - 1]);
                        set.insert(ans[i + 1][j + k - 1]);
                        set.insert(ans[i][j + k + 1]);
                        set.insert(ans[i + 1][j + k + 1]);
                        set.insert(ans[i + 2][j + k]);
                        let c = *op.iter().find(|c| !set.contains(c)).unwrap();
                        ans[i][j + k] = c;
                        ans[i + 1][j + k] = c;
                        a -= 1;
                    }
                } else if b > 0 {
                    for k in 0..2 {
                        let mut set = Set::new();
                        set.insert(ans[i + k - 1][j]);
                        set.insert(ans[i + k - 1][j + 1]);
                        set.insert(ans[i + k][j - 1]);
                        set.insert(ans[i + k][j + 2]);
                        set.insert(ans[i + k + 1][j]);
                        set.insert(ans[i + k + 1][j + 1]);
                        let c = *op.iter().find(|c| !set.contains(c)).unwrap();
                        ans[i + k][j] = c;
                        ans[i + k][j + 1] = c;
                        b -= 1;
                    }
                } else {
//                    unreachable!()
                }
            }
        }
        for ans in ans[1..=h].iter() {
            let s = ans[1..=w].iter().cloned().collect::<String>();
            writeln!(out, "{}", s).ok();
        }
    }
}

fn main() {
    run();
}
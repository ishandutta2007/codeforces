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

fn diff(a: usize, b: usize) -> usize {
    a.max(b) - a.min(b)
}

fn run() {
    input! {
        h: usize,
        w: usize,
        p: usize,
        a: [[usize1; w]; h],
    }
    let mut b = vec![vec![]; p];
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            b[*a].push((i, j));
        }
    }
    let inf = std::usize::MAX / 2;
    let mut dp = vec![vec![inf; w]; h];
    for &(x, y) in b[0].iter() {
        dp[x][y] = x + y;
    }
    for b in b.windows(2) {
        let s = &b[0];
        let t = &b[1];
        if s.len().saturating_mul(t.len()) <= h * w {
            for &(a, b) in s.iter() {
                for &(c, d) in t.iter() {
                    dp[c][d] = dp[c][d].min(dp[a][b] + diff(a, c) + diff(b, d));
                }
            }
        } else {
            let mut memo = vec![vec![inf; w]; h];
            let mut p = vec![];
            for &(x, y) in s.iter() {
                memo[x][y] = dp[x][y];
                p.push((memo[x][y], x, y));
            }
            p.sort();
            let d = p[0].0;
            p.reverse();
            let mut now = vec![];
            for d in d.. {
                while p.last().map_or(false, |p| p.0 == d) {
                    let (_, x, y) = p.pop().unwrap();
                    now.push((x, y));
                }
                if now.is_empty() {
                    break;
                }
                let mut next = vec![];
                for (x, y) in now {
                    if memo[x][y] != d {
                        continue;
                    }
                    let d = d + 1;
                    for &(u, v) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                        if u < h && v < w && memo[u][v] > d {
                            memo[u][v] = d;
                            next.push((u, v));
                        }
                    }
                }
                now = next;
            }
            for &(x, y) in t.iter() {
                dp[x][y] = memo[x][y];
            }
        }
    }
    let (x, y) = b[p - 1][0];
    let ans = dp[x][y];
    println!("{}", ans);
}

fn main() {
    run();
}
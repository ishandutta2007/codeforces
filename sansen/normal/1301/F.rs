//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        h: usize,
        w: usize,
        k: usize,
        a: [[usize1; w]; h],
        q: usize,
        ask: [(usize1, usize1, usize1, usize1); q],
    }
    let mut p = vec![vec![]; k];
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            p[*a].push((i, j));
        }
    }
    let mut memo = vec![];
    for s in 0..k {
        let mut dp = vec![vec![100u8; w]; h];
        let mut q = std::collections::VecDeque::new();
        for p in p[s].iter() {
            dp[p.0][p.1] = 0;
            q.push_back(*p);
        }
        let mut used = vec![false; k];
        while let Some((x, y)) = q.pop_front() {
            for &(i, j) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if i < h && j < w && dp[i][j] > dp[x][y] + 1 {
                    dp[i][j] = dp[x][y] + 1;
                    q.push_back((i, j));
                }
            }
            if !used[a[x][y]] {
                used[a[x][y]] = true;
                for &(a, b) in p[a[x][y]].iter() {
                    if dp[a][b] > dp[x][y] + 1 {
                        dp[a][b] = dp[x][y] + 1;
                        q.push_back((a, b));
                    }
                }
            }
        }
        memo.push(dp);
    }
    use std::cmp::*;
    for (p, q, r, s) in ask {
        let mut ans = min(100, max(p, r) - min(p, r) + max(q, s) - min(q, s)) as u8;
        for dp in memo.iter() {
            ans = min(ans, dp[p][q] + dp[r][s] + 1);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
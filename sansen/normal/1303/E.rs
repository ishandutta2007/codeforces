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
use std::cmp::min;

fn convert(s: &[char]) -> Vec<usize> {
    let mut ans = vec![];
    for c in s.iter() {
        ans.push(c.to_digit(36).unwrap() as usize - 10);
    }
    ans
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        test: [(chars, chars); t],
    }
    for (s, t) in test {
        let s = convert(&s);
        let t = convert(&t);
        let n = s.len();
        let m = t.len();
        let f = 26;
        let mut next = vec![vec![n; 800 + 1]; f];
        for i in (0..n).rev() {
            for j in 0..f {
                next[j][i] = next[j][i + 1];
            }
            next[s[i]][i] = i;
        }
        let mut find = false;
        for i in 0..=m {
            let (l, r) = t.split_at(i);
            let h = l.len();
            let w = r.len();
            let mut dp = vec![vec![n + 1; w + 1]; h + 1];
            dp[0][0] = 0;
            for i in 0..=h {
                for j in 0..=w {
                    let v = dp[i][j];
                    if v >= n {
                        continue;
                    }
                    if i < h {
                        let x = next[l[i]][v];
                        dp[i + 1][j] = min(dp[i + 1][j], x + 1);
                    }
                    if j < w {
                        let x = next[r[j]][v];
                        dp[i][j + 1] = min(dp[i][j + 1], x + 1);
                    }
                }
            }
            if dp[h][w] <= n {
                find = true;
                break;
            }
        }
        if find {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}
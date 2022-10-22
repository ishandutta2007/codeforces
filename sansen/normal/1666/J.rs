fn run() {
    input! {
        n: usize,
        c: [[i64; n]; n],
    }
    let save = c.clone();
    let mut c = c;
    for i in 0..n {
        for j in 0..i {
            c[i][j] = 0;
        }
        c[i].push(0);
    }
    c.push(vec![0; n + 1]);
    for i in (0..n).rev() {
        for j in (0..n).rev() {
            c[i][j] += c[i + 1][j] + c[i][j + 1] - c[i + 1][j + 1];
        }
    }
    let sum = |l: usize, r: usize| -> i64 {
        assert!(l < r);
        c[l][l] - c[l][r] - c[r][l] + c[r][r]
    };
    let mut dp = vec![vec![(0, 0); n]; n];
    for l in (0..n).rev() {
        for r in l..n {
            if l == r {
                dp[l][r] = (save[l].iter().sum::<i64>(), l);
                continue;
            }
            let mut val = std::i64::MAX;
            let mut pos = l;
            for m in l..=r {
                let mut v = 0;
                if l < m {
                    v += dp[l][m - 1].0;
                }
                if m < r {
                    v += dp[m + 1][r].0;
                }
                if val > v {
                    val = v;
                    pos = m;
                }
            }
            val += c[0][l] - c[l][l] - c[0][r + 1] + c[l][r + 1];
            val += c[l][r + 1] - c[r + 1][r + 1];
            dp[l][r] = (val, pos);
        }
    }
    let mut parent = vec![0; n];
    let mut dfs = vec![(0, n - 1, !0)];
    while let Some((l, r, p)) = dfs.pop() {
        let (_, m) = dp[l][r];
        parent[m] = p + 1;
        if l < m {
            dfs.push((l, m - 1, m));
        }
        if m < r {
            dfs.push((m + 1, r, m));
        }
    }
    println!("{}", join(&parent, " "));
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
pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
}
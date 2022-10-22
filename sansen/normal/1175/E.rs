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
        n: usize,
        m: usize,
        p: [(usize, usize); n],
        ask: [(usize, usize); m],
    }
    let mut p = p;
    p.sort_by_key(|p| (p.0, 500_000 - p.1));
    let mut a = vec![p[0]];
    for p in p[1..].iter() {
        if a.last().unwrap().1 < p.1 {
            a.push(*p);
        }
    }
    let n = a.len();
    let mut r = 0;
    let mut right: Vec<usize> = (0..n).collect();
    for l in 0..n {
        r = std::cmp::max(r, l);
        while r < n - 1 && a[r + 1].0 <= a[l].1 {
            r += 1;
        }
        right[l] = r;
    }
    let mut dp = vec![];
    dp.push(right);
    let len = 20;
    for i in 1..len {
        let mut next = vec![0; n];
        for j in 0..n {
            next[j] = dp[i - 1][dp[i - 1][j]];
        }
        dp.push(next);
    }
    for (l, r) in ask {
        if a[0].0 > l {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut p = match a.binary_search_by(|a| a.0.cmp(&l)) {
            Ok(k) => k,
            Err(k) => {
                assert!(k > 0);
                k - 1
            },
        };
        if a[dp[len - 1][p]].1 < r {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = 0;
        for i in (0..len).rev() {
            if a[dp[i][p]].1 < r {
                ans += 1 << i;
                p = dp[i][p];
            }
        }
        while a[p].1 < r {
            ans += 1;
            p = dp[0][p];
        }
        ans += 1;
        assert!(a[p].1 >= r);
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
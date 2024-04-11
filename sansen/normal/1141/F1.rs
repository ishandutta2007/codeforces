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
    input! {
        n: usize,
        a: [i64; n],
    }
    let mut s = vec![0; n + 1];
    for i in (0..n).rev() {
        s[i] = a[i] + s[i + 1];
    }
    let mut z = vec![];
    for l in 0..n {
        for r in (l + 1)..=n {
            let s = s[l] - s[r];
            z.push(s);
        }
    }
    z.sort();
    z.dedup();
    let mut dp = vec![vec![]; z.len()];
    for l in (0..n).rev() {
        for r in (l + 1)..=n {
            let s = s[l] - s[r];
            let k = z.binary_search(&s).unwrap();
            match dp[k].last() {
                None => dp[k].push((l, r)),
                Some(&(x, _)) if r <= x => dp[k].push((l, r)),
                _ => (),
            }
        }
    }
    let ans = dp.iter().max_by_key(|a| a.len()).unwrap();
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).unwrap();
    for &(l, r) in ans {
        writeln!(out, "{} {}", l + 1, r).unwrap();
    }
}

fn main() {
    run();
}
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
        s: chars,
        q: usize,
        p: [(usize1, usize); q],
    }
    let n = s.len();
    let mut map = std::collections::BTreeMap::new();
    for (i, c) in "qwertyuiopasdfghjklzxcvbnm".chars().enumerate() {
        map.insert(c, i);
    }
    let f = 26;
    assert!(map.len() == f);
    let s: Vec<usize> = s.into_iter().map(|c| *map.get(&c).unwrap()).collect();
    let mut sum = vec![vec![0; n + 1]; f];
    for i in (0..n).rev() {
        for j in 0..f {
            sum[j][i] = sum[j][i + 1];
        }
        sum[s[i]][i] += 1;
    }
    for (l, r) in p {
        if r - l == 1 {
            writeln!(out, "Yes").ok();
        } else if s[l] != s[r - 1] {
            writeln!(out, "Yes").ok();
        } else {
            let mut cnt = vec![0; f];
            for i in 0..f {
                cnt[i] = sum[i][l] - sum[i][r];
            }
            let mut k = 0;
            for i in 0..f {
                if i != s[l] && i != s[r - 1] && cnt[i] > 0 {
                    k += 1;
                }
            }
            if k >= 2 {
                writeln!(out, "Yes").ok();
            } else {
                writeln!(out, "No").ok();
            }
        }
    }
}

fn main() {
    run();
}
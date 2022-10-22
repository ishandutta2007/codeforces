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

// 10->2 
// 
// M^3 

use std::io::*;

fn convert(s: &[u8]) -> Vec<usize> {
    let mut dp = vec![0u64];
    for s in s.chunks(9) {
        let mut val = 0;
        let mut mul = 1;
        for c in s.iter() {
            val = 10 * val + (*c - b'0') as u64;
            mul *= 10;
        }
        dp.iter_mut().for_each(|dp| *dp *= mul);
        dp.push(0);
        dp[0] += val;
        for i in 0..dp.len() {
            let q = dp[i] >> 32;
            dp[i] -= q << 32;
            if q > 0 {
                dp[i + 1] += q;
            }
        }
        while dp.last().map_or(false, |p| *p == 0) {
            dp.pop();
        }
    }
    // 32
    dp.into_iter().map(|dp| dp as usize).collect()
}

fn run() {
    input! {
        n: usize,
        s: [bytes; n],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let w = std::mem::size_of::<usize>() * 8;
    let mut s = s.into_iter().map(|s| convert(&s)).collect::<Vec<_>>();
    let len = s.iter().map(|s| s.len()).max().unwrap();
    s.iter_mut().for_each(|s| s.resize(len, 0));
    let mut base: Vec<(Vec<usize>, Vec<usize>)> = vec![];
    for (i, mut s) in s.into_iter().enumerate() {
        let mut used = vec![0; n / w + 1];
        for base in base.iter() {
            for j in (0..len).rev() {
                if base.0[j] ^ s[j] == s[j] {
                    continue;
                }
                if base.0[j] ^ s[j] < s[j] {
                    s.iter_mut().zip(base.0.iter()).for_each(|p| *p.0 ^= *p.1);
                    used.iter_mut().zip(base.1.iter()).for_each(|p| *p.0 ^= *p.1);
                }
                break;
            }
        }
        if s.iter().any(|s| *s != 0) {
            writeln!(out, "0").ok();
            used[i / w] |= 1 << (i % w);
            base.push((s, used));
        } else {
            let mut ans = vec![];
            for i in 0..n {
                if used[i / w] >> (i % w) & 1 == 1 {
                    ans.push(i);
                }
            }
            let mut s = String::new();
            s.push_str(&format!("{}", ans.len()));
            for a in ans {
                s.push_str(&format!(" {}", a));
            }
            writeln!(out, "{}", s).ok();
        }
    }
}

fn main() {
    run();
}
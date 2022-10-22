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

fn solve(t: Vec<u8>) -> Option<(Vec<usize>, Vec<usize>)> {
    let t = t.into_iter().map(|t| (t - b'a') as usize).collect::<Vec<_>>();
    let w = 26;
    let mut dp = vec![(0, 0); w];
    for (i, &x) in t.iter().enumerate() {
        dp[x].0 = i + 1;
        dp[x].1 += 1;
    }
    let mut ord = vec![];
    let mut cnt = vec![0; w];
    while let Some(&(r, c)) = dp.iter().filter(|p| p.0 > 0).min() {
        let mut x = 0;
        for i in 0..w {
            if dp[i] == (r, c) {
                dp[i] = (0, 0);
                x = i;
            }
        }
        if c % (ord.len() + 1) != 0 {
            return None;
        }
        cnt[x] = c / (ord.len() + 1);
        ord.push(x);
    }
    let mut sum = vec![0; w];
    let mut pos = 0;
    for t in t.iter() {
        sum[*t] += 1;
        pos += 1;
        if sum == cnt {
            break;
        }
    }
    if sum != cnt {
        return None;
    }
    let mut s = Vec::from(&t[..pos]);
    let mut a = vec![];
    for c in ord.iter() {
        a.extend_from_slice(&s);
        s = s.into_iter().filter(|p| *p != *c).collect();
    }
    if a == t {
        Some((Vec::from(&t[..pos]), ord))
    } else {
        None
    }
}

fn run() {
    input! {
        t: usize,
        ask: [bytes; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for t in ask {
        if let Some((s, p)) = solve(t) {
            let s = s.into_iter().map(|c| (c as u8 + b'a') as char).collect::<String>();
            let p = p.into_iter().map(|c| (c as u8 + b'a') as char).collect::<String>();
            writeln!(out, "{} {}", s, p).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
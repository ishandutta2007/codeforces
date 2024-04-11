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
        s: [u32; n],
        t: [u32; n],
    }
    let mut s: Vec<(u32, usize)> = (1..=n).map(|k| (s[k - 1], k)).collect();
    s.sort();
    let mut t = t;
    t.sort();
    let t = t;
    let mut ans = vec![];
    let mut j = 0;
    for i in 0..n {
        while s[i].0 < t[i] && j < n {
            if s[j].0 > t[j] {
                let d = std::cmp::min(t[i] - s[i].0, s[j].0 - t[j]);
                ans.push((s[i].1, s[j].1, d));
                s[i].0 += d;
                s[j].0 -= d;
            } else {
                j += 1;
            }
        }
        if s[i].0 != t[i] {
            writeln!(out, "NO").ok();
            return;
        }
    }
    assert!(ans.len() <= 5 * n);
    writeln!(out, "YES\n{}", ans.len()).ok();
    for (a, b, d) in ans {
        writeln!(out, "{} {} {}", a, b, d).ok();
    }
}

fn main() {
    run();
}
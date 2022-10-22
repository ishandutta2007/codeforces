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
        e: [(usize, usize, u64); m],
    }
    let mut a = vec![0; n + 1];
    let mut b = vec![0; n + 1];
    for &(s, t, d) in e.iter() {
        a[s] += d;
        b[t] += d;
    }
    let mut x = vec![];
    let mut y = vec![];
    for i in 1..=n {
        if a[i] > b[i] {
            x.push((i, a[i] - b[i]));
        } else if a[i] < b[i] {
            y.push((i, b[i] - a[i]));
        }
    }
    let mut ans = vec![];
    while x.len() > 0 && y.len() > 0 {
        let a = x.last_mut().unwrap();
        let b = y.last_mut().unwrap();
        if a.1 == 0 {
            x.pop();
        } else if b.1 == 0 {
            y.pop();
        } else {
            let z = std::cmp::min(a.1, b.1);
            a.1 -= z;
            b.1 -= z;
            ans.push((a.0, b.0, z));
        }
    }
    writeln!(out, "{}", ans.len()).ok();
    for e in ans {
        writeln!(out, "{} {} {}", e.0, e.1, e.2).ok();
    }
}

fn main() {
    run();
}
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
        m: u64,
        f: [usize; n],
        w: [u64; n],
    }
    let mut t: Vec<_> = (0..n).map(|k| (k, 0, std::u64::MAX)).collect();
    let mut s: Vec<_> = (0..n).map(|k| (f[k], w[k], w[k])).collect();
    let merge = |a: &[(usize, u64, u64)], b: &[(usize, u64, u64)]| -> Vec<(usize, u64, u64)> {
        let mut ans = vec![];
        for &(x, y, z) in a.iter() {
            let (a, b, c) = b[x];
            ans.push((a, y + b, std::cmp::min(z, c)));
        }
        ans
    };
    let mut m = m;
    while m > 0 {
        if m & 1 == 1 {
            t = merge(&t, &s);
        }
        s = merge(&s, &s);
        m >>= 1;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (_, a, b) in t {
        writeln!(out, "{} {}", a, b).ok();
    }
}

fn main() {
    run();
}
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
        a: [u64; n],
        q: usize,
        p: [(usize1, u64, usize); q],
    }
    let sum = a.iter().fold(0, |s, a| s + *a);
    let mut hit = vec![0; n];
    let mut hit_sum = 0;
    let mut map = std::collections::BTreeMap::<(usize, u64), usize>::new();
    for (s, t, u) in p {
        if let Some(v) = map.remove(&(s, t)) {
            if hit[v] <= a[v] {
                hit_sum -= 1;
            }
            hit[v] -= 1;
        }
        if u > 0 {
            let u = u - 1;
            assert!(map.insert((s, t), u).is_none());
            if hit[u] < a[u] {
                hit_sum += 1;
            }
            hit[u] += 1;
        }
        let ans = sum - hit_sum;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
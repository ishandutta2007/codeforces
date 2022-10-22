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

fn run() {
    input! {
        n: usize,
        m: usize,
        k: usize,
        p: [(usize1, usize); m],
    }
    let mut p = p;
    p.sort_by_key(|p| p.0 + p.1);
    let mut left = vec![0; n - k + 1];
    for (i, s) in left.iter_mut().enumerate() {
        for &(l, r) in p.iter() {
            let l = l.max(i);
            let r = r.min(i + k);
            *s += r.saturating_sub(l);
        }
    }
    let mut ans = *left.iter().max().unwrap();
    let mut right = vec![0; n - k + 1];
    for &(l, r) in p.iter() {
        for (i, s) in left.iter_mut().enumerate() {
            let l = l.max(i);
            let r = r.min(i + k);
            *s -= r.saturating_sub(l);
        }
        for (i, s) in right.iter_mut().enumerate() {
            let l = l.max(i);
            let r = r.min(i + k);
            *s += r.saturating_sub(l);
        }
        ans = ans.max(*left.iter().max().unwrap() + *right.iter().max().unwrap());
    }
    println!("{}", ans);
}

fn main() {
    run();
}
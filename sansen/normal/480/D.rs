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

// in-outor
// DP?
// N=500
// 1
// A (W, S) min(A - W, S) 
//
// 

type Map = std::collections::BTreeMap<(usize, usize, usize), u64>;

fn calc(l: usize, r: usize, st: usize, p: &[(usize, usize, usize, usize, u64)], dp: &mut Map) -> u64 {
    if let Some(&v) = dp.get(&(l, r, st)) {
        return v;
    }
    let mut val = vec![];
    for &(a, b, w, s, v) in p.iter() {
        if (l <= a && b < r || l < a && b <= r) && w <= st {
            val.push((a - l, b - l, calc(a, b, s.min(st - w), p, dp) + v));
        }
    }
    val.sort();
    let mut memo = vec![0; r - l + 1];
    let mut x = 0;
    for &(a, b, v) in val.iter() {
        while x < a {
            x += 1;
            memo[x] = memo[x].max(memo[x - 1]);
        }
        memo[b] = memo[b].max(memo[x] + v);
    }
    let ans = memo.iter().max().cloned().unwrap_or(0);
    dp.insert((l, r, st), ans);
    ans
}

fn run() {
    input! {
        n: usize,
        s: usize,
        p: [(usize, usize, usize, usize, u64); n],
    }
    let ans = calc(0, 2 * n, s, &p, &mut Map::new());
    println!("{}", ans);
}

fn main() {
    run();
}
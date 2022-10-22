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

// max ceil(|h[i] - h[j]| / (j - i))
// 1 <= i < j <= n
// |h_i - h_j| <= L * |j - i| L
// 
// q <= 100
// 1 <= l < r <= n
// 0 <= a <= 10^8
// q=1 
// j-i=1 

fn run() {
    input! {
        n: usize,
        q: usize,
        a: [i64; n],
        ask: [(usize1, usize); q],
    }
    for (l, r) in ask {
        let mut d = vec![];
        let mut next = (0..=(r - l)).map(|k| {
            (k - 1, k + 1)
        }).collect::<Vec<_>>();
        for (i, a) in a[l..r].windows(2).enumerate() {
            d.push(((a[0] - a[1]).abs(), i + 1));
        }
        d.sort();
        let mut ans = 0;
        for (d, k) in d {
            let (l, r) = next[k];
            next[l].1 = r;
            next[r].0 = l;
            ans += (k - l) as i64 * (r - k) as i64 * d;
        }
        println!("{}", ans);
    }
}

fn main() {
    run();
}
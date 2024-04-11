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
        s: bytes,
    }
    let s = s.into_iter().map(|s| (s - b'a') as usize).collect::<Vec<_>>();
    const F: usize = 26;
    let mut index = vec![vec![]; F];
    for (i, s) in s.iter().enumerate() {
        index[*s].push(i);
    }
    let mut ans = 0f64;
    for (_, index) in index.iter().enumerate() {
        let mut cnt = vec![[0; F]; s.len()];
        for &x in index.iter() {
            for (cnt, s) in cnt.iter_mut().zip(s.iter().cycle().skip(x)) {
                cnt[*s] += 1;
            }
        }
        let max = cnt.iter().map(|c| {
            c.iter().filter(|c| **c == 1).count()
        }).max().unwrap();
        ans += max as f64 / s.len() as f64;
    }
    println!("{:.7}", ans);
}

fn main() {
    run();
}
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
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    let mut s = s;
    while s.len() > 0 && s[0].iter().all(|s| *s == b'0') {
        s.remove(0);
    }
    if s.is_empty() {
        println!("0");
        return;
    }
    let mut dp = (0, 10000000);
    for s in s[1..].iter().rev() {
        if let Some(x) = s.iter().position(|c| *c == b'1') {
            let y = s.iter().rposition(|c| *c == b'1').unwrap();
            dp = ((dp.0 + 2 * y).min(dp.1 + w + 1), (dp.1 + 2 * (w + 1 - x)).min(dp.0 + w + 1));
        }
        dp.0 += 1;
        dp.1 += 1;
    }
    let x = s[0].iter().position(|c| *c == b'1').unwrap();
    let y = s[0].iter().rposition(|c| *c == b'1').unwrap();
    let ans = (dp.0 + y).min(dp.1 + w + 1 - x);
    println!("{}", ans);
}

fn main() {
    run();
}
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
    let mut k = 0;
    while 2 * k + 1 < s.len() {
        k = 2 * k + 1;
    }
    let w = (k + 1).trailing_zeros() as usize;
    let mut ans = String::new();
    let mut pos = vec![0];
    let mut dp = vec![false; s.len()];
    for i in 0..(s.len() - k) {
        dp.iter_mut().for_each(|p| *p = false);
        for p in pos.drain(..) {
            dp[p] = true;
        }
        let mut op = b'z' + 1;
        for (j, &c) in s.iter().enumerate() {
            if !dp[j] {
                continue;
            }
            let used = j - i;
            for k in 0..w {
                if used >> k & 1 == 0 {
                    dp[j + (1 << k)] = true;
                }
            }
            if c < op {
                op = c;
                pos.clear();
                pos.push(j + 1);
            } else if c == op {
                pos.push(j + 1);
            }
        }
        ans.push(op as char);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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
        a: [usize; n],
        ask: [usize; m],
    }
    let size = (300_000usize + 1).next_power_of_two();
    let mut dp = vec![false; 2 * size];
    for a in a {
        dp[a + size] = true;
    }
    for i in (1..size).rev() {
        dp[i] = dp[2 * i] && dp[2 * i + 1];
    }
    let mut xor = 0;
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for x in ask {
        xor ^= x;
        let mut pos = 1;
        let mut w = size.trailing_zeros() as usize;
        let mut ans = 0;
        while pos < size {
            assert!(!dp[pos] && w > 0);
            w -= 1;
            if xor >> w & 1 == 1 {
                if dp[2 * pos + 1] {
                    ans |= 1 << w;
                    pos = 2 * pos;
                } else {
                    pos = 2 * pos + 1;
                }
            } else {
                if dp[2 * pos] {
                    ans |= 1 << w;
                    pos = 2 * pos + 1;
                } else {
                    pos = 2 * pos;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
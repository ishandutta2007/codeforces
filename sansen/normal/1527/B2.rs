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

use std::io::Write;

// 
// Alice reverse 
// Bob 1
// ...
// Bob 1palindrome 
// Alice 2
// Bob2...
// 
//
// 0010 Alice
//
// 
// 
// 10
// palindrome
// Alice
// bob2, alice2...
// 
// palindrome 
// 0

fn run() {
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (mut n, mut s) in ask {
        if n % 2 == 1 && s[n / 2] == b'1' {
            s.remove(n / 2);
            n -= 1;
        }
        let cnt = if n % 2 == 0 {
            let mut cnt = 0;
            for i in 0..(n / 2) {
                if s[i] != s[n - 1 - i] {
                    cnt += 1;
                    s[i] = b'1';
                    s[n - 1 - i] = b'1';
                }
            }
            let a = s[..(n / 2)].iter().filter(|c| **c == b'0').count();
            let mut res;
            let mut val = -cnt;
            if a > 0 {
                res = val + 2;
            } else {
                res = val;
            }
            if cnt > 0 {
                let mut val = -cnt + 2;
                if a > 0 {
                    res = res.min(val - 2);
                }
            }
            res
        } else {
            let mut cnt = 0;
            for i in 0..(n / 2) {
                if s[i] != s[n - 1 - i] {
                    cnt += 1;
                    s[i] = b'1';
                    s[n - 1 - i] = b'1';
                }
            }
            let a = s[..(n / 2)].iter().filter(|c| **c == b'0').count();
            let mut val = -cnt + 1;
            if a > 0 {
                val += -2;
            }
            val
        };
        let ans = if cnt < 0 {
            "ALICE"
        } else if cnt == 0 {
            "DRAW"
        } else {
            "BOB"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
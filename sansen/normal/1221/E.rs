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
        q: usize,
        p: [(usize, usize, chars); q],
    }
    for (a, b, s) in p {
        let mut p = vec![];
        let mut cnt = 0;
        for c in s {
            if c == '.' {
                cnt += 1;
            } else if cnt > 0 {
                if cnt >= b {
                    p.push(cnt);
                }
                cnt = 0;
            }
        }
        if cnt >= b {
            p.push(cnt);
        }
        p.sort();
        let n = p.len();
        let ans = if n == 0 {
            "NO"
        } else if p[0] < a {
            "NO"
        } else if n > 1 && p[n - 2] >= 2 * b {
            "NO"
        } else {
            let len = p[n - 1];
            let mut win = false;
            for i in a..=len {
                let x = i - a;
                let y = len - i;
                if (b <= x && x < a) || x >= 2 * b {
                    continue;
                }
                if (b <= y && y < a) || y >= 2 * b {
                    continue;
                }
                let m = n - 1 + if x >= a {1} else {0} + if y >= a {1} else {0};
                if m % 2 == 0 {
                    win = true;
                    break;
                }
            }
            if win {"YES"} else {"NO"}
        };
        writeln!(out, "{}", ans).unwrap();
    }
}

fn main() {
    run();
}
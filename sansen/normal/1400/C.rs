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

//

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(chars, usize); t],
    }
    for (s, x) in ask {
        let n = s.len();
        let mut ans = vec!['1'; n];
        for i in 0..n {
            if s[i] == '0' {
                if i >= x {
                    ans[i - x] = '0';
                }
                if i + x < n {
                    ans[i + x] = '0';
                }
            }
        }
        let mut ok = true;
        for i in 0..n {
            if s[i] == '1' {
                let mut cond = false;
                cond |= i >= x && ans[i - x] == '1';
                cond |= i + x < n && ans[i + x] == '1';
                ok &= cond;
            }
        }
        if ok {
            writeln!(out, "{}", ans.into_iter().collect::<String>()).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
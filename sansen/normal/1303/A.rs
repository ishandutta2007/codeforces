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
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    input! {
        source = s,
        t: usize,
    }
    for _ in 0..t {
        s.clear();
        std::io::stdin().read_line(&mut s).unwrap();
        input! {
            source = s,
            s: chars,
        }
        if s.iter().all(|c| *c == '0') {
            writeln!(out, "0").ok();
            continue;
        }
        let mut l = 0;
        while s[l] != '1' {
            l += 1;
        }
        let mut r = s.len() - 1;
        while s[r] != '1' {
            r -= 1;
        }
        let mut ans = 0;
        for i in l..=r {
            if s[i] == '0' {
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
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
        ask: [(chars, chars, chars); q],
    }
    for (mut s, mut t, mut p) in ask {
        let mut j = 0;
        for c in s.iter_mut() {
            while j < t.len() && t[j] != *c {
                j += 1;
            }
            if j < t.len() {
                t[j] = '$';
                *c = '$';
            }
        }
        if !s.iter().all(|c| *c == '$') {
            writeln!(out, "NO").ok();
            continue;
        }
        for c in t.iter_mut() {
            if *c == '$' {
                continue;
            }
            if let Some(k) = p.iter().position(|p| *p == *c) {
                p[k] = '$';
                *c = '$';
            }
        }
        if t.iter().all(|t| *t == '$') {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}
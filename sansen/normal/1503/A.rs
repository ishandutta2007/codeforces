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

fn run() {
    input! {
        t: usize,
        ask: [(usize, bytes); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, s) in ask {
        let mut cond = true;
        cond &= s[0] == b'1';
        cond &= s[n - 1] == b'1';
        cond &= s.iter().filter(|c| **c == b'1').count() % 2 == 0;
        cond &= s.iter().filter(|c| **c == b'0').count() % 2 == 0;
        if !cond {
            writeln!(out, "NO").ok();
            continue;
        }
        writeln!(out, "YES").ok();
        let mut a = String::new();
        let mut b = String::new();
        a.push('(');
        b.push('(');
        let mut same = ['(', ')'];
        let mut diff = ['(', ')'];
        for c in s[1..(n - 1)].iter() {
            if *c == b'1' {
                a.push(same[0]);
                b.push(same[0]);
                same.swap(0, 1);
            } else {
                a.push(diff[0]);
                b.push(diff[1]);
                diff.swap(0, 1);
            }
        }
        a.push(')');
        b.push(')');
        writeln!(out, "{}\n{}", a, b).ok();
    }
}

fn main() {
    run();
}
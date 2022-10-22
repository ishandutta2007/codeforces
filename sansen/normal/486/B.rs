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
        h: usize,
        w: usize,
        b: [[u8; w]; h],
    }
    let mut a = vec![vec![1; w]; h];
    for (i, b) in b.iter().enumerate() {
        for (j, b) in b.iter().enumerate() {
            if *b == 0 {
                a[i] = vec![0; w];
                for k in 0..h {
                    a[k][j] = 0;
                }
            }
        }
    }
    for (i, b) in b.iter().enumerate() {
        for (j, b) in b.iter().enumerate() {
            let mut val = 0;
            val |= a[i].iter().fold(0, |s, a| s | *a);
            val |= (0..h).fold(0, |s, x| s | a[x][j]);
            if val != *b {
                println!("NO");
                return;
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES").ok();
    for a in a {
        for (j, a) in a.iter().enumerate() {
            if j > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", *a).ok();
        }
        writeln!(out).ok();
    }
}

fn main() {
    run();
}
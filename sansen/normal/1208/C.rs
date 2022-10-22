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
        n: usize,
    }
    let mut a = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            let x = i / 4;
            let y = j / 4;
            let z = i % 4;
            let w = j % 4;
            a[i][j] = 16 * (x * n / 4 + y) + 4 * z + w;
        }
    }
    for i in 0..n {
        let mut v = 0;
        for j in 0..n {
            v ^= a[i][j];
        }
        assert!(v == 0);
    }
    for j in 0..n {
        let mut v = 0;
        for i in 0..n {
            v ^= a[i][j];
        }
        assert!(v == 0);
    }
    let mut used = vec![false; n * n];
    for i in 0..n {
        for j in 0..n {
            assert!(!used[a[i][j]]);
            used[a[i][j]] = true;
        }
    }
    for i in 0..n {
        for j in 0..n {
            if j > 0 {
                write!(out, " ").unwrap();
            }
            write!(out, "{}", a[i][j]).unwrap();
        }
        writeln!(out, "").unwrap();
    }
}

fn main() {
    run();
}
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
        m: usize,
        a: [[u8; m]; n],
    }
    let mut b = vec![vec![0; m]; n];
    let mut ans = vec![];
    for i in 0..(n - 1) {
        for j in 0..(m - 1) {
            if a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1 {
                ans.push((i, j));
                b[i][j] = 1;
                b[i][j + 1] = 1;
                b[i + 1][j] = 1;
                b[i + 1][j + 1] = 1;
            }
        }
    }
    for i in 0..n {
        for j in 0..m {
            if a[i][j] != b[i][j] {
                writeln!(out, "-1").unwrap();
                return;
            }
        }
    }
    writeln!(out, "{}", ans.len()).unwrap();
    ans.iter().for_each(|&(a, b)| writeln!(out, "{} {}", a + 1, b + 1).unwrap());
}

fn main() {
    run();
}
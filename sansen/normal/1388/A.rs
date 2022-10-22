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

fn solve(n: usize) -> Option<(usize, usize, usize, usize)> {
    let a = [6, 10, 14, 15, 21, 22];
    for (i, &x) in a.iter().enumerate() {
        for (j, &y) in a.iter().enumerate().take(i) {
            for &z in a.iter().take(j) {
                let s = x + y + z;
                if s >= n {
                    continue;
                }
                let w = n - s;
                if w != x && w != y && w != z {
                    return Some((x, y, z, w));
                }
            }
        }
    }
    None
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [usize; t],
    }
    for n in ask {
        if let Some(ans) = solve(n) {
            writeln!(out, "YES\n{} {} {} {}", ans.0, ans.1, ans.2, ans.3).ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}
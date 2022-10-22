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
    input! {
        s: bytes,
    }
    let n = s.len();
    let mut set = std::collections::BTreeSet::new();
    let mut can = vec![vec![false; n + 1]; 2];
    can[0][n] = true;
    can[1][n] = true;
    for i in (5..n).rev() {
        if i + 2 <= n {
            let x = &s[i..(i + 2)];
            let mut v = false;
            v |= can[1][i + 2];
            v |= can[0][i + 2] && (i + 2 + 2 > n || x != &s[(i + 2)..(i + 4)]);
            if v {
                set.insert(x);
                can[0][i] = true;
            }
        }
        if i + 3 <= n {
            let x = &s[i..(i + 3)];
            let mut v = false;
            v |= can[0][i + 3];
            v |= can[1][i + 3] && (i + 3 + 3 > n || x != &s[(i + 3)..(i + 6)]);
            if v {
                set.insert(x);
                can[1][i] = true;
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", set.len()).ok();
    for s in set {
        for c in s.iter() {
            write!(out, "{}", *c as char).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}
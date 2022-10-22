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
        t: usize,
        p: [(usize, chars); t],
    }
    let mut map = std::collections::BTreeMap::new();
    map.insert('L', (-1, 0));
    map.insert('R', (1, 0));
    map.insert('U', (0, 1));
    map.insert('D', (0, -1));
    for (n, s) in p {
        let mut memo = std::collections::BTreeMap::new();
        let mut pos = (0, 0);
        let mut ans = (0, 2 * n);
        memo.insert(pos, 0);
        for (i, &c) in s.iter().enumerate() {
            let d = *map.get(&c).unwrap();
            pos.0 += d.0;
            pos.1 += d.1;
            if let Some(p) = memo.insert(pos, i + 1) {
                if ans.1 - ans.0 > i + 1 - p {
                    ans = (p, i + 1);
                }
            }
        }
        if ans.1 < 2 * n {
            writeln!(out, "{} {}", ans.0 + 1, ans.1).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
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
        n: usize,
        a: [usize; n],
        q: usize,
        ask: [(bytes, usize); q],
    }
    let w = 100000;
    let mut cnt = vec![0; w + 1];
    let mut elem = vec![0; 2 * w + 1];
    for a in a {
        let c = &mut cnt[a];
        *c += 1;
        elem[*c] += 1;
    }
    for (op, x) in ask {
        let c = &mut cnt[x];
        if op[0] == b'+' {
            *c += 1;
            elem[*c] += 1;
        } else {
            elem[*c] -= 1;
            *c -= 1;
        }
        let mut ok = false;
        ok |= elem[8] >= 1;
        ok |= elem[6] >= 1 && elem[2] >= 2;
        ok |= elem[4] >= 2;
        ok |= elem[4] >= 1 && elem[2] >= 3;
        let ans = if ok {
            "YES"
        } else {
            "NO"
        };
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
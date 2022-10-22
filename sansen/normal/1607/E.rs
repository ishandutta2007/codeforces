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
        ask: [(i32, i32, bytes); t],
    }
    // l, r, u, d  x, y
    let next = |r: (i32, i32, i32, i32), mut pos: (i32, i32), op: u8| -> ((i32, i32, i32, i32), (i32, i32)) {
        let dir = match op {
            b'L' => (0, -1),
            b'R' => (0, 1),
            b'U' => (-1, 0),
            _ => (1, 0),
        };
        pos.0 += dir.0;
        pos.1 += dir.1;
        ((r.0.min(pos.0), r.1.max(pos.0), r.2.min(pos.1), r.3.max(pos.1)), pos)
    };
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (h, w, s) in ask {
        let mut range = (0, 0, 0, 0);
        let mut pos = (0, 0);
        for s in s {
            let (a, b) = next(range, pos, s);
            if a.1 - a.0 + 1 > h || a.3 - a.2 + 1 > w {
                break;
            }
            range = a;
            pos = b;
        }
        writeln!(out, "{} {}", -range.0 + 1, -range.2 + 1).ok();
    }
}

fn main() {
    run();
}
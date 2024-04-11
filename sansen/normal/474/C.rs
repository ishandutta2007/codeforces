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
        n: usize,
        ask: [[(i32, i32, i32, i32); 4]; n],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for mut p in ask {
        let rotate = |p: &mut (i32, i32, i32, i32)| {
            let dx = p.0 - p.2;
            let dy = p.1 - p.3;
            p.0 = p.2 - dy;
            p.1 = p.3 + dx;
        };
        let mut ans = -1;
        for i in 0..4 {
            for j in 0..4 {
                for k in 0..4 {
                    for l in 0..4 {
                        let mut q = p.clone();
                        q.sort();
                        let mut ok = false;
                        for i in 1..3 {
                            let dx = q[i].0 - q[0].0;
                            let dy = q[i].1 - q[0].1;
                            if dx == 0 && dy == 0 {
                                continue;
                            }
                            let mut dir = (dx, dy);
                            let mut pos = (q[0].0, q[0].1);
                            let mut j = 0;
                            while j < 4 && q.binary_search_by_key(&pos, |q| (q.0, q.1)).is_ok() {
                                pos = (pos.0 + dir.0, pos.1 + dir.1);
                                dir = (-dir.1, dir.0);
                                j += 1;
                            }
                            if j == 4 {
                                ok = true;
                            }
                        }
                        if ok && (ans == -1 || ans > i + j + k + l) {
                            ans = i + j + k + l;
                        }
                        rotate(&mut p[3]);
                    }
                    rotate(&mut p[2]);
                }
                rotate(&mut p[1]);
            }
            rotate(&mut p[0]);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
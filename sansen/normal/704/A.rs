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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        q: usize,
        ask: [(u8, usize1); q],
    }
    let mut cnt = vec![0; n];
    let mut read = vec![0; n];
    let mut history = vec![];
    let mut s = 0;
    let mut ans = 0;
    for (op, x) in ask {
        if op == 1 {
            history.push((x, cnt[x]));
            cnt[x] += 1;
            ans += 1;
        } else if op == 2 {
            ans -= cnt[x] - read[x];
            read[x] = cnt[x];
        } else {
            let y = (x + 1).min(history.len());
            for i in s..y {
                let (p, q) = history[i];
                if q >= read[p] {
                    read[p] += 1;
                    ans -= 1;
                }
            }
            s = s.max(y);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
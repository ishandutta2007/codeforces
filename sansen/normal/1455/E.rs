// ---------- begin next_permutation ----------
fn next_permutation<T: Ord>(a: &mut [T]) -> bool {
    a.windows(2).rposition(|a| a[0] < a[1]).map_or(false, |x| {
        let y = a.iter().rposition(|b| a[x] < *b).unwrap();
        a.swap(x, y);
        a[(x + 1)..].reverse();
        true
    })
}
// ---------- end next_permutation ----------
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
        t: usize,
        p: [[(i64, i64); 4]; t],
    }
    for p in p {
        let mut p = p;
        p.sort();
        let mut x = p.iter().map(|p| p.0).collect::<Vec<_>>();
        let mut y = p.iter().map(|p| p.1).collect::<Vec<_>>();
        x.sort();
        y.sort();
        let mut ans = std::i64::MAX;
        while {
            let mut val = std::i64::MAX;
            for (x, y) in [(&x, &y), (&y, &x)].iter() {
            for &(x, len) in [(x[0], x[3] - x[0]), (x[0], x[2] - x[0]), (x[1], x[2] - x[1]), (x[1], x[3] - x[1])].iter() {
                for &y in [y[0], y[1], y[2] - len, y[3] - len].iter() {
                    let q = [(x, y), (x + len, y), (x, y + len), (x + len, y + len)];
                    let mut s = 0;
                    for (p, q) in p.iter().zip(q.iter()) {
                        s += (p.0 - q.0).abs() + (p.1 - q.1).abs();
                    }
                    val = val.min(s);
                }
                p.iter_mut().for_each(|p| std::mem::swap(&mut p.0, &mut p.1));                                  }
            }
            ans = ans.min(val);
            next_permutation(&mut p)
        } {}
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
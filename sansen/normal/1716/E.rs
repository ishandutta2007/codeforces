use std::io::Write;

fn run() {
    input! {
        n: usize,
        a: [i64; 1 << n],
        q: usize,
        ask: [usize; q],
    }
    // l, r, all, max
    let mut data = vec![vec![]; 2 << n];
    for (data, &a) in data[(1 << n)..].iter_mut().zip(a.iter()) {
        let p = (a.max(0), a.max(0), a, a.max(0));
        *data = vec![p];
    }
    for i in (1..(1 << n)).rev() {
        let (l, r) = (
            std::mem::take(&mut data[2 * i]),
            std::mem::take(&mut data[2 * i + 1]),
        );
        let mut next = vec![];
        next.extend(l.iter().zip(r.iter()).map(|(l, r)| {
            (
                l.0.max(l.2 + r.0),
                r.1.max(r.2 + l.1),
                l.2 + r.2,
                l.3.max(r.3).max(l.1 + r.0),
            )
        }));
        next.extend(l.iter().zip(r.iter()).map(|(l, r)| {
            (
                r.0.max(r.2 + l.0),
                l.1.max(l.2 + r.1),
                l.2 + r.2,
                l.3.max(r.3).max(r.1 + l.0),
            )
        }));
        data[i] = next;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut bit = 0;
    for k in ask {
        bit ^= 1 << k;
        writeln!(out, "{}", data[1][bit].3).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
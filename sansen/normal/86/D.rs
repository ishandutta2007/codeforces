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
        q: usize,
        a: [u32; n],
        ask: [(usize1, usize); q],
    }
    let mut z = a.clone();
    z.sort();
    z.dedup();
    let mut a = a;
    for a in a.iter_mut() {
        *a = z.binary_search(a).unwrap() as u32;
    }
    let batch = ((2 * n) as f64 / ((3 * q) as f64).sqrt()).ceil() as usize;
    let mut ord = (0..q).collect::<Vec<_>>();
    ord.sort_by_cached_key(|x| {
        let (l, r) = ask[*x];
        let q = l / batch;
        if q % 2 == 0 {
            (q, r)
        } else {
            (q, !r)
        }
    });
    let mut ans = vec![0; q];
    let mut cnt = vec![0u32; z.len()];
    let mut x = 0;
    let mut y = 0;
    let mut sum = 0usize;
    for k in ord {
        let (l, r) = ask[k];
        for i in (l..x).chain(y..r) {
            let a = a[i] as usize;
            let c = &mut cnt[a];
            sum += (2 * *c + 1) as usize * z[a] as usize;
            *c += 1;
        }
        for i in (x..l).chain(r..y) {
            let a = a[i] as usize;
            let c = &mut cnt[a];
            *c -= 1;
            sum -= (2 * *c + 1) as usize * z[a] as usize;
        }
        x = l;
        y = r;
        ans[k] = sum;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
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

fn cond(b: bool) {
    if !b {
        println!("NO");
        std::process::exit(0);
    }
}

fn run() {
    input! {
        n: usize,
        e: [(usize, usize); n - 1],
    }
    cond(e.iter().all(|e| e.1 == n));
    let mut cnt = vec![0; n];
    let mut elem = vec![false; n];
    for e in e.iter() {
        cnt[e.0] += 1;
        elem[e.0] = true;
    }
    let mut edge = vec![];
    let mut last = (0..n).collect::<Vec<_>>();
    for i in (1..n).rev() {
        if elem[i] {
            continue;
        }
        let x = cnt.iter().rposition(|c| *c > 1).unwrap();
        cond(x > i);
        cnt[x] -= 1;
        edge.push((last[x], i));
        last[x] = i;
    }
    for i in 1..n {
        if cnt[i] > 0 {
            edge.push((last[i], n));
        }
    }
    println!("YES");
    for (a, b) in edge {
        println!("{} {}", a, b);
    }
}

fn main() {
    run();
}
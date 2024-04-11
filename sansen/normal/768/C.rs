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

fn run() {
    input! {
        n: usize,
        k: usize,
        v: usize,
        a: [usize; n],
    }
    let m = 1 << 10;
    let mut cnt = vec![0; m];
    for a in a {
        cnt[a] += 1;
    }
    let mut next = vec![0; m];
    for _ in 0..k {
        next.iter_mut().for_each(|c| *c = 0);
        let mut p = 0;
        for (i, c) in cnt.iter().enumerate() {
            let x = *c / 2;
            let y = *c - x;
            if p == 0 {
                next[i ^ v] += y;
                next[i] += x;
            } else {
                next[i] += y;
                next[i ^ v] += x;
            }
            p ^= *c & 1;
        }
        std::mem::swap(&mut cnt, &mut next);
    }
    let l = cnt.iter().position(|c| *c > 0).unwrap();
    let r = cnt.iter().rposition(|c| *c > 0).unwrap();
    println!("{} {}", r, l);
}

fn main() {
    run();
}
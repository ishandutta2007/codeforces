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

fn can(m: usize, a: &[usize], p: &[(usize, usize)]) -> bool {
    let mut last = m;
    let mut free = 0;
    let mut rem = vec![];
    rem.extend_from_slice(a);
    for &(d, t) in p.iter().rev() {
        if d > m {
            continue;
        }
        if last > d {
            free += last - d;
            last = d;
        }
        while rem[t] > 0 && last > 0 {
            rem[t] -= 1;
            last -= 1;
        }
    }
    free += last;
    2 * rem.into_iter().fold(0, |s, a| s + a) <= free
}

fn run() {
    input! {
        n: usize,
        m: usize,
        a: [usize; n],
        p: [(usize, usize1); m],
    }
    let mut p = p;
    p.sort_by_key(|p| p.0);
    let mut ng = 0;
    let mut ok = 400_000;
    while ok - ng > 1 {
        let m = (ok + ng) / 2;
        if can(m, &a, &p) {
            ok = m;
        } else {
            ng = m;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}
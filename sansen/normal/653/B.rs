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

fn run() {
    input! {
        n: usize,
        q: usize,
        op: [(bytes, bytes); q],
    }
    let mut p = vec![];
    for (a, b) in op {
        let a = (a[1] - b'a') as usize * 6 + (a[0] - b'a') as usize;
        let b = (b[0] - b'a') as usize;
        p.push((a, b));
    }
    let mut ok = vec![false; 6];
    ok[0] = true;
    for _ in 2..=n {
        let mut next = vec![false; ok.len() * 6];
        for (i, _) in ok.iter().enumerate().filter(|p| *p.1) {
            for &(a, b) in p.iter() {
                if i % 6 == b {
                    next[(i / 6) * 36 + a] = true;
                }
            }
        }
        ok = next;
    }
    let ans = ok.into_iter().filter(|p| *p).count();
    println!("{}", ans);
}

fn main() {
    run();
}
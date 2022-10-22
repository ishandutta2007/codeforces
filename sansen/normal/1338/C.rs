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

use std::io::Write;

#[allow(dead_code)]
fn test() {
    let mut set = std::collections::BTreeSet::new();
    for i in 1..100000 {
        set.insert(i);
    }
    for _ in 0..100 {
        let a = *set.iter().next().unwrap();
        let mut p = (0, 0);
        for &b in set.iter() {
            if set.contains(&(a ^ b)) {
                p = (b, a ^ b);
                break;
            }
        }
        let (b, c) = p;
        set.remove(&a);
        set.remove(&b);
        set.remove(&c);
        println!("{:b} {:b} {:b}", a, b, c);
    }
}

fn run() {
    input! {
        n: usize,
        a: [u64; n],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let bit = [[0, 1, 2, 3], [0, 2, 3, 1], [0, 3, 1, 2]];
    for mut n in a {
        let mut s = 3u64;
        while n > s {
            n -= s;
            s *= 4;
        }
        n -= 1;
        s /= 3;
        let mut ans = (1 + n % 3) * s;
        let mut k = 1;
        while k < s {
            ans += bit[(n % 3) as usize][(n / 3 / k % 4) as usize] * k;
            k *= 4;
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
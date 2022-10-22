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

fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        p: [usize1; n],
    }
    let mut q = p.clone();
    q.sort();
    q.dedup();
    if q.len() < n {
        println!("-1");
        return;
    }
    let mut a = vec![];
    let mut used = vec![false; n];
    for i in 0..n {
        if used[i] {
            continue;
        }
        used[i] = true;
        let mut k = p[i];
        let mut c = 1;
        while k != i {
            used[k] = true;
            c += 1;
            k = p[k];
        }
        if c % 2 == 0 {
            a.push(c / 2);
        } else {
            a.push(c);
        }
    }
    a.sort();
    let ans = a.iter().fold(1, |s, a| s / gcd(s, *a) * *a);
    println!("{}", ans);
}

fn main() {
    run();
}
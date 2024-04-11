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

fn factor(mut n: u64) -> Vec<u64> {
    let mut f = vec![];
    for i in 2.. {
        if i * i > n {
            break;
        }
        if n % i == 0 {
            f.push(i);
            while n % i == 0 {
                n /= i;
            }
        }
    }
    if n > 1 {
        f.push(n);
    }
    f
}

fn run() {
    input! {
        t: usize,
        p: [(u64, u64); t],
    }
    for (p, q) in p {
        let ans = if p % q != 0 {
            p
        } else {
            let f = factor(q);
            let mut d = vec![1];
            let mut p = p;
            for f in f {
                let mut c = 0;
                while p % f == 0 {
                    p /= f;
                    c += 1;
                }
                let len = d.len();
                let mut mul = 1;
                for _ in 1..=c {
                    mul *= f;
                    for i in 0..len {
                        let v = d[i] * mul;
                        d.push(v);
                    }
                }
            }
            p * *d.iter().filter(|d| **d % q != 0).max().unwrap()
        };
        println!("{}", ans);
    }
}

fn main() {
    run();
}
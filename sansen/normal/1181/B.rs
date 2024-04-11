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

fn calc(a: &[u8], b: &[u8]) -> Vec<u32> {
    assert!(a[0] != b'0' && b[0] != b'0');
    let a = a.iter().map(|a| (*a - b'0') as u32).rev().collect::<Vec<_>>();
    let b = b.iter().map(|a| (*a - b'0') as u32).rev().collect::<Vec<_>>();
    let mut c = vec![0; a.len() + b.len()];
    for (c, a) in c.iter_mut().zip(a.iter()) {
        *c += *a;
    }
    for (c, a) in c.iter_mut().zip(b.iter()) {
        *c += *a;
    }
    for i in 0..(c.len() - 1) {
        c[i + 1] += c[i] / 10;
        c[i] %= 10;
    }
    while *c.last().unwrap() == 0 {
        c.pop();
    }
    c.reverse();
    c
}

fn run() {
    input! {
        n: usize,
        s: bytes,
    }
    let mut x = vec![];
    for (i, s) in s.iter().enumerate() {
        if *s != b'0' && i > 0 {
            x.push(i);
        }
    }
    x.sort_by_key(|&x| x.max(n - x));
    x.truncate(2);
    if x.len() == 1 {
        let p = x[0];
        let a = calc(&s[..p], &s[p..]);
        let mut s = String::new();
        for a in a {
            s.push_str(&format!("{}", a));
        }
        println!("{}", s);
    } else {
        let p = x[0];
        let q = x[1];
        let a = calc(&s[..p], &s[p..]);
        let b = calc(&s[..q], &s[q..]);
        let a = if a.len() < b.len() {
            a
        } else if a.len() > b.len() {
            b
        } else {
            a.min(b)
        };
        let mut s = String::new();
        for a in a {
            s.push_str(&format!("{}", a));
        }
        println!("{}", s);
    }
}

fn main() {
    run();
}
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
        _n: usize,
        s: bytes,
        t: bytes,
    }
    let mut a = std::collections::BTreeSet::new();
    let mut b = std::collections::BTreeSet::new();
    for (i, (s, t)) in s.iter().zip(t.iter()).enumerate() {
        match (*s, *t) {
            (b'0', b'1') => {
                a.insert(i);
            },
            (b'1', b'0') => {
                b.insert(i);
            },
            _ => (),
        }
    }
    if a.len() != b.len() {
        println!("-1");
        return;
    }
    let mut ans = 0;
    while !a.is_empty() {
        ans += 1;
        let (a, b) = if *a.iter().next().unwrap() < *b.iter().next().unwrap() {
            (&mut a, &mut b)
        } else {
            (&mut b, &mut a)
        };
        let mut s = 0;
        loop {
            let p = s;
            use std::ops::Bound::*;
            if let Some(&x) = a.range((Included(&s), Unbounded)).next() {
                if let Some(&y) = b.range((Included(&x), Unbounded)).next() {
                    s = y + 1;
                    a.remove(&x);
                    b.remove(&y);
                }
            }
            if p == s {
                break;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
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

fn valid(a: &[u32], b: &[u32]) -> bool {
    assert!(a.len() == b.len());
    for (a, b) in a.iter().zip(b.iter()) {
        if *a != *b {
            return *a < *b;
        }
    }
    true
}

fn run() {
    input! {
        n: usize,
        k: usize,
        a: chars,
    }
    let a: Vec<u32> = a.into_iter().map(|c| c.to_digit(10).unwrap()).collect();
    let mut b = vec![];
    for a in a.iter().take(k).cycle().take(n) {
        b.push(*a);
    }
    if !valid(&a, &b) {
        let mut c = vec![];
        c.extend_from_slice(&a[..k]);
        c[k - 1] += 1;
        for i in (0..k).rev() {
            if c[i] > 9 {
                c[i] -= 10;
                c[i - 1] += 1;
            }
        }
        for (b, c) in b.iter_mut().zip(c.iter().cycle()) {
            *b = *c;
        }
    }
    assert!(valid(&a, &b));
    let mut out = String::new();
    out.push_str(&b.len().to_string());
    out.push('\n');
    b.iter().for_each(|d| out.push_str(&d.to_string()));
    println!("{}", out);
}

fn main() {
    run();
}
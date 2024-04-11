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

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {a} else {gcd(b, a % b)}
}

fn run() {
    input! {
        r: usize,
        c: usize,
    }
    if r == 1 && c == 1 {
        println!("0");
        return;
    } else if r == 1 {
        for i in 1..=c {
            if i > 1 {
                print!(" {}", i + 1);
            } else {
                print!("{} ", i + 1);
            }
        }
        println!();
        return;
    } else if c == 1 {
        for i in 1..=r {
            println!("{}", i + 1);
        }
        return;
    }
    let mut a = vec![vec![0; c]; r];
    let mut out = String::new();
    for i in 1..=r {
        for j in (r + 1)..=(r + c) {
            let v = i * j;
            a[i - 1][j - r - 1] = v;
            out.push_str(&format!("{} ", v));
        }
        out.pop();
        out.push('\n');
    }
    let mut b = vec![];
    for i in 0..r {
        let mut g = 0;
        for j in 0..c {
            g = gcd(g, a[i][j]);
        }
        b.push(g);
    }
    for j in 0..c {
        let mut g = 0;
        for i in 0..r {
            g = gcd(g, a[i][j]);
        }
        b.push(g);
    }
    b.sort();
    b.dedup();
    assert!(b.len() == r + c);
    assert!(*b.last().unwrap() == r + c);
    print!("{}", out);
}

fn main() {
    run();
}
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

fn run() {
    input! {
        n: usize,
        k: usize,
        a: [usize; n],
    }
    let m = 100_000;
    let mut p = vec![1; m + 1];
    for i in 0..=m {
        p[i] = i;
    }
    for i in 2..=m {
        if p[i] == i {
            for j in (i..=m).step_by(i) {
                p[j] = i;
            }
        }
    }
    let mut ans = 0u64;
    let mut map = std::collections::BTreeMap::<Vec<(usize, usize)>, u64>::new();
    for a in a {
        let mut a = a;
        let mut f = vec![];
        while a > 1 {
            let p = p[a];
            let mut c = 0;
            while a % p == 0 {
                a /= p;
                c += 1;
            }
            c %= k;
            if c != 0 {
                f.push((p, c));
            }
        }
        let v: Vec<(usize, usize)> = f.iter().map(|f| (f.0, k - f.1)).collect();
        if let Some(&c) = map.get(&v) {
            ans += c;
        }
        *map.entry(f).or_insert(0) += 1;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
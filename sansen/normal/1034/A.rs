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

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let mut a = a;
    let mut g = a[0];
    for a in a.iter() {
        g = gcd(g, *a);
    }
    let mut one = true;
    for a in a.iter_mut() {
        *a /= g;
        one &= *a == 1;
    }
    if one {
        println!("-1");
        return;
    }
    let m = 15_000_000;
    let mut factor = (0..=m).collect::<Vec<_>>();
    for i in (2..).take_while(|p| p * p <= m) {
        if i == factor[i] {
            for j in i..=(m / i) {
                factor[j * i] = i;
            }
        }
    }
    let mut cnt = vec![0; m + 1];
    for a in a {
        let mut x = a;
        while x > 1 {
            let p = factor[x];
            cnt[p] += 1;
            while x % p == 0 {
                x /= p;
            }
        }
    }
    let ans = cnt.into_iter().map(|c| n - c).min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
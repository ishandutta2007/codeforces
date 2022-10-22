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

fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 {a} else {gcd(b, a % b)}
}

fn run() {
    input! {
        n: usize,
        a: [u32; n],
    }
    let mut g = vec![vec![0; n]; n];
    for i in 0..n {
        for j in 0..n {
            g[i][j] = gcd(a[i], a[j]);
        }
    }
    let mut dp_l = vec![vec![false; n]; n];
    let mut dp_r = vec![vec![false; n]; n];
    for i in 0..n {
        dp_l[i][i] = true;
        dp_r[i][i] = true;
    }
    for len in 2..=n {
        for l in 0..=(n - len) {
            let r = l + len - 1;
            for i in (l + 1)..=r {
                if g[l][i] > 1 && dp_r[l + 1][i] && dp_l[i][r] {
                    dp_l[l][r] = true;
                }
            }
            for i in l..r {
                if g[r][i] > 1 && dp_r[l][i] && dp_l[i][r - 1] {
                    dp_r[l][r] = true;
                }
            }
        }
    }
    for i in 0..n {
        if dp_r[0][i] && dp_l[i][n - 1] {
            println!("Yes");
            return;
        }
    }
    println!("No");
}

fn main() {
    run();
}
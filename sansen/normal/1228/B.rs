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
        h: usize,
        w: usize,
        r: [usize; h],
        c: [usize; w],
    }
    let mut a = vec![vec![2; w]; h];
    for i in 0..h {
        for j in 0..r[i] {
            a[i][j] = 1;
        }
        if r[i] < w {
            a[i][r[i]] = 0;
        }
    }
    for j in 0..w {
        for i in 0..c[j] {
            if a[i][j] == 0 {
                println!("0");
                return;
            }
            a[i][j] = 1;
        }
        if c[j] < h {
            if a[c[j]][j] == 1 {
                println!("0");
                return;
            }
            a[c[j]][j] = 0;
        }
    }
    let mut ans = 1;
    const MOD: u64 = 1_000_000_007;
    for i in 0..h {
        for j in 0..w {
            if a[i][j] == 2 {
                ans = 2 * ans % MOD;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
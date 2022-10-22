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

const MOD: u64 = 1_000_000_007;

fn mod_pow(r: u64, mut n: u64) -> u64 {
    let mut t = 1;
    let mut s = r % MOD;
    while n > 0 {
        if n & 1 == 1 {
            t = t * s % MOD;
        }
        s = s * s % MOD;
        n >>= 1;
    }
    t
}

fn run() {
    input! {
        n: u64,
        m: u64,
        k: i32,
    }
    if k == -1 && m % 2 != n % 2 {
        println!("0");
        return;
    }
    let ans = mod_pow(mod_pow(2, n - 1), m - 1);
    println!("{}", ans);
}

fn main() {
    run();
}
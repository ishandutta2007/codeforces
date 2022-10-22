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

const MOD: u64 = 1_000_000 + 3;

fn pow(mut r: u64, mut n: u64) -> u64 {
    let mut t = 1;
    while n > 0 {
        if n & 1 == 1 {
            t = t * r % MOD;
        }
        r = r * r % MOD;
        n >>= 1;
    }
    t
}

fn run() {
    input! {
        n: u64,
        k: u64,
    }
    if n <= 60 && 2u64.pow(n as u32) < k {
        println!("1 1");
        return;
    }
    let mut cnt = n;
    let mut m = k - 1;
    while m > 0 {
        cnt += m / 2;
        m /= 2;
    }
    let cnt = cnt;
    let inv = pow(2, MOD - 2);
    let p = pow(2, n);
    let de = pow(p, k) * pow(inv, cnt) % MOD;
    let mut fact = 1;
    for i in (0..k).take(MOD as usize) {
        fact = fact * (p + MOD - i) % MOD;
    }
    fact = fact * pow(inv, cnt) % MOD;
    let nu = (de - fact + MOD) % MOD;
    println!("{} {}", nu, de);
}

fn main() {
    run();
}
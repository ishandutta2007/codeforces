fn pow_mod(r: u64, mut n: u64, m: u32) -> u64 {
    assert!(m > 0);
    if m == 1 {
        return 0;
    }
    let m = m as u64;
    let mut t = 1;
    let mut s = r % m;
    while n > 0 {
        if n & 1 == 1 {
            t = t * s % m;
        }
        s = s * s % m;
        n >>= 1;
    }
    t
}

fn is_prime(n: u64) -> bool {
    (2u64..).take_while(|p| p * p <= n).all(|p| n % p != 0)
}

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

use std::io::Write;

fn run() {
    input! {
        n: usize,
    }
    if n == 1 {
        println!("YES\n1");
        return;
    }
    if n == 2 {
        println!("YES\n1\n2");
        return;
    }
    if n == 4 {
        println!("YES\n1\n3\n2\n4");
        return;
    }
    if !is_prime(n as u64) {
        println!("NO");
        return;
    }
    let mut ans = vec![1];
    for i in 1..(n - 1) {
        let v = ((i + 1) as u64 * pow_mod(i as u64, (n - 2) as u64, n as u32) % n as u64) as usize;
        ans.push(v);
    }
    ans.push(n);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES").ok();
    for a in ans {
        writeln!(out, "{}", a).ok();
    }
}

fn main() {
    run();
}
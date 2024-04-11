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

fn calc(mut n: u128) -> u128 {
    let mut sum = 0;
    let mut cnt = 0;
    let mut sup = 0;
    let mut d = vec![];
    while n > 0 {
        d.push(n % 10);
        n /= 10;
    }
    for &d in d.iter().rev() {
        let ns = sum * 10 + cnt * 45 + sup * d + d * (d - 1) / 2;
        let nc = 10 * cnt + d;
        sum = ns;
        cnt = nc;
        sup += d;
    }
    sum + sup
}

fn run() {
    input! {
        a: u128,
    }
    let mut map = std::collections::BTreeMap::<u128, u128>::new();
    for i in 1.. {
        let mut ng = 0;
        let mut ok = a.saturating_mul(i);
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if calc(mid) >= i * a {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        let key = calc(ok) % a;
        if let Some(l) = map.get(&key) {
            if l + 1 <= ok {
                println!("{} {}", l + 1, ok);
                return;
            }
        }
        map.insert(key, ok);
    }
}

fn main() {
    run();
}
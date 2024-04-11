use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    input! {
        t: usize,
        ask: [(usize, usize); t],
    }
    for (n, m) in ask {
        let mut dp = Map::new();
        dp.insert((false, 0, 0), 1u64);
        for i in 0..61 {
            let n = n >> i & 1;
            let m = m >> i & 1;
            let mut next = Map::new();
            for ((less, carry, bit), w) in dp {
                for j in 0..2 {
                    let less = j < m || (j == m && less);
                    let v = n + carry + j;
                    let carry = v / 2;
                    let bit = bit ^ j ^ (v & 1);
                    *next.entry((less, carry, bit)).or_insert(0) += w;
                }
            }
            dp = next;
        }
        let ans = dp.iter().filter(|p| *p.0 == (true, 0, 1)).map(|p| *p.1).sum::<u64>();
        println!("{}", ans);
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
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

fn run() {
    input! {
        n: usize,
        a: [usize1; n],
    }
    let mut used = vec![false; n];
    let mut cycle = vec![];
    for i in 0..n {
        if used[i] {
            continue;
        }
        let mut set = std::collections::BTreeSet::new();
        let mut pos = i;
        while !used[pos] && set.insert(pos) {
            used[pos] = true;
            pos = a[pos];
        }
        if set.contains(&pos) {
            let mut cnt = 1;
            let s = pos;
            pos = a[pos];
            while pos != s {
                cnt += 1;
                pos = a[pos];
            }
            cycle.push(cnt);
        }
    }
    const MOD: u64 = 1_000_000_007;
    let pow = |n: usize| -> u64 {
        let mut s = 1;
        for _ in 0..n {
            s = 2 * s % MOD;
        }
        s
    };
    let mut ans = 1;
    let mut rem = n;
    for c in cycle {
        rem -= c;
        ans = ans * (pow(c) - 2) % MOD; 
    }
    ans = ans * pow(rem) % MOD;
    println!("{}", ans);
}

fn main() {
    run();
}
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

fn compress(a: &mut Vec<(u64, u64)>) {
    a.sort_by_key(|p| (p.0, !p.1));
    a.dedup_by(|a, b| {
        a.0 <= b.1 + 1 && {
            b.1 = b.1.max(a.1);
            true
        }
    });
}

fn partition(a: &[(u64, u64)], w: u32) -> (Vec<(u64, u64)>, Vec<(u64, u64)>) {
    let mut l = vec![];
    let mut r = vec![];
    let x = 1 << w;
    for &(s, t) in a.iter() {
        if t < x {
            l.push((s, t));
        } else if x <= s {
            r.push((s ^ x, t ^ x));
        } else {
            l.push((s, x - 1));
            r.push((0, t ^ x));
        }
    }
    (l, r)
}

// C 
fn dfs(a: &[(u64, u64)], b: &[(u64, u64)], w: u32) -> Vec<(u64, u64)> {
    if a.is_empty() || b.is_empty() {
        return vec![];
    }
    let all = vec![(0, (1 << w) - 1)];
    if a == all || b == all {
        return all;
    }
    let w = w - 1;
    let (p, q) = partition(a, w);
    let (r, s) = partition(b, w);
    let mut res = vec![];
    res.extend(dfs(&p, &r, w).into_iter());
    res.extend(dfs(&q, &s, w).into_iter());
    res.extend(
        dfs(&p, &s, w)
            .iter()
            .map(|p| (p.0 | (1 << w), p.1 | (1 << w))),
    );
    res.extend(
        dfs(&q, &r, w)
            .iter()
            .map(|p| (p.0 | (1 << w), p.1 | (1 << w))),
    );
    compress(&mut res);
    res
}

fn run() {
    input! {
        n: usize,
        a: [(u64, u64); n],
        m: u64,
        b: [(u64, u64); m],
    }
    let mut a = a;
    let mut b = b;
    compress(&mut a);
    compress(&mut b);
    let range = dfs(&a, &b, 60);
    const MOD: u64 = 998_244_353;
    let mut ans = 0;
    for (l, r) in range {
        let mut v = (r - l + 1) % MOD * ((l + r) % MOD);
        if v % 2 != 0 {
            v += MOD;
        }
        ans += v / 2 % MOD;
    }
    ans %= MOD;
    println!("{:?}", ans);
}

fn main() {
    run();
}
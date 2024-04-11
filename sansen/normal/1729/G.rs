use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        q: usize,
        ask: [(bytes, bytes); q],
    }
    for (s, t) in ask {
        let mut z = vec![];
        z.extend(t.iter());
        z.push(b'$');
        z.extend(s.iter());
        let za = z_algorithm(&z);
        let hit = za[(t.len() + 1)..].iter().map(|z| *z == t.len()).collect::<Vec<_>>();
        let inf = std::u32::MAX / 10;
        let mut dp = vec![(inf, 0u64); s.len() + 1];
        dp[0] = (0, 1);
        const MOD: u64 = 1_000_000_007;
        let tlen = t.len();
        for i in 0..s.len() {
            let (c, w) = dp[i];
            if c == inf {
                continue;
            }
            let c = c + 1;
            let w = w % MOD;
            if let Some(x) = (i..s.len()).find(|k| hit[*k]) {
                for j in 0..tlen {
                    let j = x + j;
                    if !hit[j] {
                        continue;
                    }
                    let j = j + tlen;
                    if dp[j].0 > c {
                        dp[j] = (c, w);
                    } else if dp[j].0 == c {
                        dp[j].1 += w;
                    }
                }
            }
        }
        let mut ans = (inf, 0);
        for (i, dp) in dp.iter().enumerate() {
            if hit[i..].iter().all(|hit| !*hit) {
                if ans.0 > dp.0 {
                    ans = *dp;
                } else if ans.0 == dp.0 {
                    ans.1 += dp.1;
                }
            }
        }
        println!("{} {}", ans.0, ans.1 % MOD);
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
fn z_algorithm<T: Eq>(s: &[T]) -> Vec<usize> {
    let len = s.len();
    let mut a = vec![0; len];
    a[0] = len;
    let mut i = 1;
    let mut j = 0;
    while i < len {
        while i + j < len && s[j] == s[i + j] {
            j += 1;
        }
        a[i] = j;
        if j == 0 {
            i += 1;
            continue;
        }
        let mut k = 1;
        while i + k < len && k + a[k] < j {
            a[i + k] = a[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    a
}
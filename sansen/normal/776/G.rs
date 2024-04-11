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

use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// bitok
// l <=
// <= r
// 
// bit
// 
//
// 
//

fn calc(digit: Vec<usize>) -> usize {
    let mut ans = 0;
    for max in 1..16 {
        if max / 4 >= digit.len() {
            continue;
        }
        // maxhit
        let mut dp = [[0; 2]; 2];
        dp[0][0] = 1;
        for (i, &d) in digit.iter().enumerate().rev() {
            let ok = |x: usize| -> bool {
                if x > max {
                    return false;
                }
                if 4 * i <= max && max < 4 * (i + 1) {
                    x >> (max - 4 * i) & 1 == 1
                } else {
                    true
                }
            };
            let mut next = [[0; 2]; 2];
            for (less, dp) in dp.iter().enumerate() {
                for (hit, dp) in dp.iter().enumerate() {
                    if *dp == 0 {
                        continue;
                    }
                    for j in 0..=max {
                        if less == 0 && j > d {
                            continue;
                        }
                        let less = less | (j < d) as usize;
                        let hit = hit | (j == max) as usize;
                        if ok(j) {
                            next[less][hit] += *dp;
                        }
                    }
                }
            }
            dp = next;
        }
        ans += dp[1][1] + dp[0][1];
    }
    ans
}

fn parse(r: &[u8]) -> Vec<usize> {
    let mut v = 0;
    for r in r.iter() {
        let d = if b'0' <= *r && *r <= b'9' {
            *r - b'0'
        } else {
            10 + *r - b'a'
        };
        v = 16 * v + d as usize;
    }
    let mut res = vec![];
    while v > 0 {
        res.push(v % 16);
        v /= 16;
    }
    res
}

fn run() {
    input! {
        q: usize,
        ask: [(bytes, bytes); q],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (l, r) in ask {
        let mut ans = calc(parse(&r)) - calc(parse(&l));
        let l = parse(&l);
        if l.len() > 0 {
            let v = *l.iter().max().unwrap();
            if v > 0 && l.len() > v / 4 && l[v / 4] >> (v % 4) & 1 == 1 {
                ans += 1;
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
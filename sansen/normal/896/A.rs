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
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn run() {
    input! {
        q: usize,
        ask: [(usize, u64); q],
    }
    let f = "What are you doing at the end of the world? Are you busy? Will you save us?";
    let a = "What are you doing while sending \"";
    let b = "\"? Are you busy? Will you send \"";
    let c = "\"?";
    let mut len = vec![0u64; 100000 + 1];
    len[0] = f.len() as u64;
    let inf = 10u64.pow(18) + 2;
    for i in 1..len.len() {
        len[i] = inf.min(2 * len[i - 1] + a.len() as u64 + b.len() as u64 + c.len() as u64);
    }
    let mut ans = String::new();
    for (n, mut k) in ask {
        k -= 1;
        if k >= len[n] {
            ans.push('.');
            continue;
        }
        let mut p = '\0';
        let mut n = n;
        while n > 0 {
            if k < a.len() as u64 {
                p = a.chars().nth(k as usize).unwrap();
                break;
            }
            k -= a.len() as u64;
            if k < len[n - 1] {
                n -= 1;
                continue;
            }
            k -= len[n - 1];
            if k < b.len() as u64 {
                p = b.chars().nth(k as usize).unwrap();
                break;
            }
            k -= b.len() as u64;
            if k < len[n - 1] {
                n -= 1;
                continue;
            }
            k -= len[n - 1];
            p = c.chars().nth(k as usize).unwrap();
            break;
        }
        if n == 0 {
            p = f.chars().nth(k as usize).unwrap();
        }
        ans.push(p);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
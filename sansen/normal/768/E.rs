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

fn dfs(rem: usize, ban: u64, dp: &mut Map<(usize, u64), usize>) -> usize {
    if let Some(&g) = dp.get(&(rem, ban)) {
        return g;
    }
    let mut set = Set::new();
    for i in 1..=rem {
        if ban >> i & 1 == 0 {
            set.insert(dfs(rem - i, ban | (1u64 << i), dp));
        }
    }
    let g = (0..).find(|p| !set.contains(p)).unwrap();
    dp.insert((rem, ban), g);
    g
}

fn run() {
    input! {
        n: usize,
        s: [usize; n],
    }
    let mut dp = Map::new();
    let mut g = vec![0; 61];
    for i in 1..=60 {
        g[i] = dfs(i, 0, &mut dp);
    }
    let mut ans = 0;
    for s in s {
        ans ^= g[s];
    }
    if ans != 0 {
        println!("NO");
    } else {
        println!("YES");
    }
}

fn main() {
    run();
}
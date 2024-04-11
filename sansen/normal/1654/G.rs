pub fn join<T: std::fmt::Display>(a: &[T], sep: &str) -> String {
    use std::fmt::Write;
    let mut s = String::new();
    for (i, a) in a.iter().enumerate() {
        if i > 0 {
            write!(&mut s, "{}", sep).ok();
        }
        write!(&mut s, "{}", a).ok();
    }
    s
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

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// 
// 
// 1
// 1
// 
//
// lodge(H=0)
// H
// 
// lodge
// dp?
// 
//
// 
// 
//
// hoge
//

fn run() {
    input! {
        n: usize,
        lodge: [u8; n],
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut h = vec![0; n];
    let mut deq = Deque::new();
    for (i, lodge) in lodge.iter().enumerate() {
        if *lodge == 1 {
            deq.push_back(i);
        }
    }
    while let Some(v) = deq.pop_front() {
        for &u in g[v].iter() {
            if h[u] == 0 && lodge[u] == 0 {
                h[u] = h[v] + 1;
                deq.push_back(u);
            }
        }
    }
    let mut map = Map::new();
    for (i, h) in h.iter().enumerate() {
        map.entry(*h).or_insert(vec![]).push(i);
    }
    let insert = |map: &mut Map<i32, i32>, k: i32, v: i32| {
        if map.range(..=k).next_back().map_or(true, |p| *p.1 > v) {
            while let Some((&x, &y)) = map.range(k..).next() {
                if y >= v {
                    map.remove(&x);
                } else {
                    break;
                }
            }
            map.insert(k, v);
            true
        } else {
            false
        }
    };
    // 
    // k, v 
    // k_i < k_j  v_i > v_j
    // 
    let mut dp = vec![Map::<i32, i32>::new(); n];
    let mut ans = h.clone();
    let mut compress = vec![vec![]; n];
    for (key, v) in map {
        let mut heap = BinaryHeap::new();
        for &v in v.iter() {
            let mut map = Map::new();
            for &u in g[v].iter() {
                if h[u] < key {
                    dp[u].range(..=1).next_back().map(|(_, val)| {
                        ans[v] = ans[v].max(2 * key - *val);
                    });
                    for (&k, &v) in dp[u].iter() {
                        insert(&mut map, 0i32.max(k - 1), v);
                    }
                } else if h[u] == h[v] {
                    compress[v].push(u);
                    insert(&mut map, 0, key);
                }
            }
            heap.extend(map.iter().map(|(need, val)| (-*val, -*need, v)));
            dp[v] = map;
        }
        while let Some((val, need, v)) = heap.pop() {
            let val = -val;
            let need = -need;
            if dp[v].get(&need).map_or(true, |p| *p != val) {
                continue;
            }
            for &u in compress[v].iter() {
                if insert(&mut dp[u], need + 1, val) {
                    heap.push((-val, -(need + 1), u));
                }
            }
        }
    }
    println!("{}", join(&ans, " "));
}

fn main() {
    run();
}
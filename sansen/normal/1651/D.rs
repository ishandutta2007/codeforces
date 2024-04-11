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

fn run() {
    input! {
        n: usize,
        p: [(i32, i32); n],
    }
    let mut map = Map::new();
    for (i, p) in p.iter().enumerate() {
        map.insert(*p, i);
    }
    let dir = [(-1, 0), (0, -1), (1, 0), (0, 1)];
    let mut deq = Deque::new();
    let mut ans = vec![(0, 0); n];
    let mut used = vec![false; n];
    for (i, &(x, y)) in p.iter().enumerate() {
        if let Some(v) = dir
            .iter()
            .map(|p| (x + p.0, y + p.1))
            .find(|p| !map.contains_key(&p))
        {
            used[i] = true;
            ans[i] = v;
            deq.push_back(i);
        }
    }
    while let Some(v) = deq.pop_front() {
        let (x, y) = p[v];
        for &(dx, dy) in dir.iter() {
            let p = (x + dx, y + dy);
            if map.contains_key(&p) && !used[map[&p]] {
                used[map[&p]] = true;
                ans[map[&p]] = ans[v];
                deq.push_back(map[&p]);
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for p in ans {
        writeln!(out, "{} {}", p.0, p.1).ok();
    }
}

fn main() {
    run();
}
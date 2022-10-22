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

// N+alpha
// 1..=N  1..=N
// 
// N01 
// 1..=N 
// 10
// 
// 
//
// usize 
// 1
// 10
// 1

fn run() {
    input! {
        n: usize,
        p: [(String, usize); n],
    }
    let mut id = 1;
    let mut index = Map::new();
    for i in 1..=n {
        index.insert(i.to_string(), id);
        id += 1;
    }
    for p in p.iter() {
        index.entry(p.0.clone()).or_insert_with(|| {
            let res = id;
            id += 1;
            res
        });
    }
    let mut dummy = n + 1;
    while index.contains_key(&dummy.to_string()) {
        dummy += 1;
    }
    index.insert(dummy.to_string(), id);
    let mut state = vec![None; index.len() + 1];
    let mut first = 0;
    for (i, p) in p.iter().enumerate() {
        let x = *index.get(&p.0).unwrap();
        state[x] = Some(p.1);
        if p.1 == 1 {
            first += 1;
        }
    }
    let mut free = vec![Set::new(); 2];
    let mut need = vec![Set::new(); 2];
    for i in 1..=n {
        if i <= first {
            if let Some(p) = state[i] {
                if p == 0 {
                    need[0].insert(i);
                }
            } else {
                free[1].insert(i);
            }
        } else {
            if let Some(p) = state[i] {
                if p == 1 {
                    need[1].insert(i);
                }
            } else {
                free[0].insert(i);
            }
        }
    }
    for i in (n + 1)..state.len() {
        if let Some(p) = state[i] {
            need[p].insert(i);
        }
    }
    let mut ans = vec![];
    while (free[0].len() > 0 && need[0].len() > 0) || (free[1].len() > 0 && need[1].len() > 0) {
        if let (Some(&a), Some(&b)) = (free[0].iter().next(), need[0].iter().next()) {
            free[0].remove(&a);
            need[0].remove(&b);
            ans.push((b, a));
            state[a] = state[b];
            state[b] = None;
            if b <= first {
                free[1].insert(b);
            }
        } else if let (Some(&a), Some(&b)) = (free[1].iter().next(), need[1].iter().next()) {
            free[1].remove(&a);
            need[1].remove(&b);
            ans.push((b, a));
            state[a] = state[b];
            state[b] = None;
            if first < b && b <= n {
                free[0].insert(b);
            }
        } else {
            unreachable!();
        }
    }
    let mut invalid = vec![];
    for i in 1..=n {
        let x = state[i].unwrap();
        if (i <= first) ^ (x == 1) {
            invalid.push(i);
        }
    }
    if invalid.len() > 0 {
        let len = invalid.len();
        let (l, r) = invalid.split_at(len / 2);
        ans.push((r[0], index.len()));
        let mut free = r[0];
        for (l, r) in l.iter().rev().zip(&r[1..]) {
            ans.push((*l, free));
            ans.push((*r, *l));
            free = *r;
        }
        ans.push((l[0], free));
        ans.push((index.len(), l[0]));
    }
    let mut name = vec![String::new(); index.len() + 1];
    for (s, k) in index {
        name[k] = s;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (s, t) in ans {
        writeln!(out, "move {} {}", name[s], name[t]).ok();
    }
}

fn main() {
    run();
}
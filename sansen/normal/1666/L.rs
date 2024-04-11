use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn main() {
    input! {
        n: usize,
        m: usize,
        src: usize1,
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
    }
    let mut parent = vec![(n, n); n];
    for &v in g[src].iter() {
        if let Some((v, p)) =dfs(v, src, v, &g, src, &mut parent) {
            let mut a = vec![v, p];
            let mut pos = p;
            while pos != src {
                pos = parent[pos].1;
                a.push(pos);
            }
            let mut b = vec![v];
            let mut pos = v;
            while pos != src {
                pos = parent[pos].1;
                b.push(pos);
            }
            a.reverse();
            b.reverse();
            a.iter_mut().chain(b.iter_mut()).for_each(|p| *p += 1);
            println!("Possible");
            println!("{}", a.len());
            println!("{}", join(&a, " "));
            println!("{}", b.len());
            println!("{}", join(&b, " "));
            return;
        }
    }
    println!("Impossible");
}

fn dfs(v: usize, p: usize, root: usize, g: &[Vec<usize>], src: usize, parent: &mut [(usize, usize)]) -> Option<(usize, usize)> {
    if v == src {
        return None;
    }
    if parent[v].0 != g.len() {
        if parent[v].0 != root {
            return Some((v, p));
        }
        return None;
    }
    parent[v] = (root, p);
    for &u in g[v].iter() {
        let res = dfs(u, v, root, g, src, parent);
        if res.is_some() {
            return res;
        }
    }
    None
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
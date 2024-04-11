use std::collections::*;
use std::io::Write;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

// N <= 3 
// N=4?
// 3
// 
// N-1
// wa
// N=5  3 
// #....
// ..#..
// .#...
// .....
// .....
// 
// 6  4
// 7  5
// ...
//
// 
// N <= 10^5
// 
// 
// N = 11 7
// 
// N <= 7 
// 8: 2 3
// 9: 2 31
// 10: 2 311
// 11: 3 4
//

fn dfs(pos: &mut Vec<(i32, i32)>, up: usize, k: usize, point: &[(i32, i32)]) -> bool {
    if pos.len() == k {
        if point.iter().all(|p| {
            pos.iter()
                .any(|q| p.0 == q.0 || p.1 == q.1 || p.0 - p.1 == q.0 - q.1)
        }) {
            return true;
        }
        return false;
    }
    for i in 0..up {
        pos.push(point[i]);
        if dfs(pos, i, k, point) {
            return true;
        }
        pos.pop();
    }
    false
}

fn run() {
    input!(n: i32);
    let mut pos = vec![];
    if n <= 4 {
        let mut point = vec![];
        for i in 0..n {
            for j in 0..n {
                point.push((i, j));
            }
        }
        for k in 1.. {
            pos.clear();
            if dfs(&mut pos, point.len(), k, &point) {
                break;
            }
        }
        pos.iter_mut().for_each(|p| *p = (p.0 + 1, p.1 + 1));
    } else {
        let q = (n - 2) / 3;
        let r = (n - 2) % 3;
        for i in 0..q {
            pos.push((q - i, i + 1));
        }
        for i in 0..=q {
            pos.push((q + q + 1 - i, q + 1 + i));
        }
        for i in 0..r {
            pos.push((q + 1, q + q + 1 + 1 + i));
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", pos.len()).ok();
    for (x, y) in pos {
        writeln!(out, "{} {}", x, y).ok();
    }
}

fn main() {
    run();
}

mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
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
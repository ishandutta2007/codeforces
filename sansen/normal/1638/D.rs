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
        h: usize,
        w: usize,
        a: [[u32; w]; h],
    }
    let can = |x: usize, y: usize, a: &[Vec<u32>]| -> Option<u32> {
        if !(x > 0 && y > 0 && x < h && y < w) {
            return None;
        }
        let mut p = [a[x - 1][y - 1], a[x][y], a[x - 1][y], a[x][y - 1]];
        p.sort();
        let k = p[3];
        if k > 0 && p.iter().all(|p| *p == 0 || *p == k) {
            Some(k)
        } else {
            None
        }
    };
    let mut ans = vec![];
    let mut fill = |x: usize, y: usize, a: &mut [Vec<u32>]| {
        let c = can(x, y, a).unwrap();
        ans.push((x, y, c));
        a[x][y] = 0;
        a[x - 1][y] = 0;
        a[x][y - 1] = 0;
        a[x - 1][y - 1] = 0;
    };
    let mut a = a;
    for i in 1..h {
        for j in 1..w {
            if can(i, j, &a).is_some() {
                fill(i, j, &mut a);
                let mut dfs = vec![(i, j)];
                while let Some((x, y)) = dfs.pop() {
                    for dx in [!0, 0, 1].iter() {
                        for dy in [!0, 0, 1].iter() {
                            let x = x + dx;
                            let y = y + dy;
                            if can(x, y, &a).is_some() {
                                fill(x, y, &mut a);
                                dfs.push((x, y));
                            }
                        }
                    }
                }
            }
        }
    }
    if !a.iter().flatten().all(|a| *a == 0) {
        println!("-1");
        return;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (i, j, c) in ans.into_iter().rev() {
        writeln!(out, "{} {} {}", i, j, c).ok();
    }
}

fn main() {
    run();
}
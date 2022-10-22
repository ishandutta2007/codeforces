// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

fn run() {
    input! {
        n: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut topo = vec![(0, 0)];
    for i in 0..n {
        let (v, p) = topo[i];
        let g = &mut g[v];
        if let Some(k) = g.iter().position(|u| *u == p) {
            g.remove(k);
        }
        for &u in g.iter() {
            topo.push((u, v));
        }
    }
    let mut p = vec![0; n];
    for (i, &(v, _)) in topo.iter().enumerate() {
        p[v] = i;
    }
    let mut graph = vec![(n, n); n];
    for (i, g) in g.into_iter().enumerate() {
        let v = p[i];
        if !g.is_empty() {
            graph[v].0 = p[g[0]];
            graph[v].1 = p[*g.last().unwrap()] + 1;
        } else {
            graph[v] = (v, v);
        }
    }
    let mut dp = vec![(0, 0); n];
    let mut solve = |k: usize| -> usize {
        if k == 1 {
            return n;
        }
        dp.clear();
        dp.resize(n, (0, 0));
        for (i, &(l, r)) in graph.iter().enumerate().rev() {
            let mut val = (0, 1);
            for &(a, b) in dp[l..r].iter().rev() {
                val.0 += a;
                if b + val.1 >= k {
                    val.0 += 1;
                    val.1 = 0;
                } else if val.1 > 0 {
                    val.1 = std::cmp::max(val.1, b + 1);
                }
            }
            dp[i] = val;
        }
        dp[0].0
    };
    let mut ans = vec![0; n + 1];
    let mut dfs = vec![(1, n, n, 0)];
    while let Some((l, r, lv, rv)) = dfs.pop() {
        if l > r {
            continue;
        }
        let mid = (l + r) / 2;
        let val = solve(mid);
        ans[mid] = val;
        if lv > val {
            dfs.push((l, mid - 1, lv, val));
        }
        if val > rv {
            dfs.push((mid + 1, r, val, rv));
        }
    }
    for i in (1..n).rev() {
        let v = ans[i + 1];
        ans[i].chmax(v);
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for a in ans.iter().skip(1) {
        writeln!(out, "{}", *a).ok();
    }
}

fn main() {
    run();
}
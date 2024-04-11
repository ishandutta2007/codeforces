// ---------- begin Tree DP ----------
struct TreeDP<Edge, Value, Init, Merge> {
    size: usize,
    graph: Vec<Vec<(usize, Edge)>>,
    init: Init,
    merge: Merge,
    phantom: std::marker::PhantomData<Value>,
}

impl<Edge, Value, Init, Merge> TreeDP<Edge, Value, Init, Merge>
where Edge: Clone,
      Value: Clone,
      Init: Fn(usize) -> Value,
      Merge: Fn(Value, Value, &Edge) -> Value,
{
    fn new(size: usize, init: Init, merge: Merge) -> Self {
        TreeDP {
            size: size,
            graph: vec![vec![]; size],
            init: init,
            merge: merge,
            phantom: std::marker::PhantomData,
        }
    }
    fn add_edge(&mut self, a: usize, b: usize, c: Edge) {
        assert!(a < self.size && b < self.size && a != b);
        self.graph[a].push((b, c.clone()));
        self.graph[b].push((a, c));
    }
    fn solve(&self, root: usize) -> Value {
        let size = self.size;
        let graph = &self.graph;
        let mut topo = vec![];
        let mut parent = vec![root; size];
        let mut stack = vec![root];
        while let Some(v) = stack.pop() {
            topo.push(v);
            for e in graph[v].iter() {
                if e.0 != parent[v] {
                    parent[e.0] = v;
                    stack.push(e.0);
                }
            }
        }
        assert!(topo.len() == size);
        let mut dp: Vec<Option<Value>> = (0..size).map(|_| None).collect();
        for &v in topo.iter().rev() {
            let mut now = (self.init)(v);
            for u in graph[v].iter() {
                if u.0 == parent[v] {
                    continue;
                }
                let b = dp[u.0].take().unwrap();
                now = (self.merge)(now, b, &u.1);
            }
            dp[v] = Some(now);
        }
        dp[root].take().unwrap()
    }
}
// ---------- end Tree DP ----------
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
        k: i64,
        e: [(usize1, usize1); n - 1],
    }
    let mut deg = vec![0; n];
    for &(a, b) in e.iter() {
        deg[a] += 1;
        deg[b] += 1;
    }
    // () DP
    type Value = (i64, i64);
    type Edge = ();
    let init = |v: usize| -> Value {
        let mut ans = (0, -1_000_000_000);
        if deg[v] == 1 {
            ans.1 = 0;
        }
        ans
    };
    let merge = |(a, x): Value, (b, y): Value, _c: &Edge| -> Value {
        if x + y + 1 <= k {
            (a + b, std::cmp::max(x, y + 1))
        } else {
            (a + b + 1, std::cmp::min(x, y + 1))
        }
    };
    let mut solver = TreeDP::new(n, init, merge);
    for (a, b) in e {
        solver.add_edge(a, b, ());
    }
    let mut root = 0;
    while deg[root] == 1 {
        root += 1;
    }
    let ans = solver.solve(root).0;
    println!("{}", ans + 1);
}

fn main() {
    run();
}
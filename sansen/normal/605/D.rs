struct SegmentTree<T> {
    size: usize,
    val: Vec<Option<T>>,
}

impl<T> SegmentTree<T> 
where
    T: Clone
{
    fn new(size: usize) -> Self {
        let size = size.next_power_of_two();
        SegmentTree {
            size: size,
            val: (0..(2 * size)).map(|_| None).collect(),
        }
    }
    fn update<F>(&mut self, x: usize, val: Option<T>, mut f: F)
    where
        F: FnMut(&T, &T) -> T,
    {
        assert!(x < self.size);
        let mut x = x + self.size;
        self.val[x] = val;
        let val = &mut self.val;
        x >>= 1;
        while x > 0 {
            val[x] = match (val[2 * x].as_ref(), val[2 * x + 1].as_ref()) {
                (Some(l), Some(r)) => Some(f(l, r)),
                _ => val[2 * x].clone().or_else(|| val[2 * x + 1].clone()),
            };
            x >>= 1;
        }
    }
    fn query<F>(&self, l: usize, r: usize, mut f: F)
    where
        F: FnMut(&T),
    {
        assert!(l <= r && r <= self.size);
        let mut l = self.size + l;
        let mut r = self.size + r;
        let val = &self.val;
        while l < r {
            if l & 1 == 1 {
                val[l].as_ref().map(|p| f(p));
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                val[r].as_ref().map(|p| f(p));
            }
            l >>= 1;
            r >>= 1;
        }
    }
}
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
        p: [(i32, i32, i32, i32); n],
    }
    let mut p = p;
    p.insert(0, (0, 0, 0, 0));
    let mut z = vec![];
    let mut e = vec![];
    for (i, &(a, b, c, d)) in p.iter().enumerate() {
        z.push(a);
        z.push(c);
        e.push((b, a, 0, i));
        e.push((d, c, 1, i));
    }
    z.sort();
    z.dedup();
    e.sort();
    let mut leaf = vec![None; z.len()];
    let mut seg = SegmentTree::new(z.len());
    let mut edge = vec![];
    let mut id = p.len();
    for (_, x, op, k) in e {
        let v = z.binary_search(&x).unwrap();
        if op == 0 {
            if let Some(u) = leaf[v].take() {
                let p = id;
                id += 1;
                edge.push((p, u, 0));
                edge.push((p, k, 0));
                leaf[v] = Some(p);
            } else {
                leaf[v] = Some(k);
            }
            seg.update(v, leaf[v], |a, b| {
                let res = id;
                id += 1;
                edge.push((res, *a, 0));
                edge.push((res, *b, 0));
                res
            });
        } else {
            seg.query(0, v + 1, |u| {
                edge.push((k, *u, 1));
            });
        }
    }
    let mut graph = vec![vec![]; id];
    for &(s, t, c) in edge.iter() {
        graph[s].push((t, c));
    }
    let mut dp = vec![(n + 1, 0); graph.len()];
    dp[0] = (0, 0);
    let mut q = std::collections::VecDeque::new();
    q.push_back((0, 0));
    while let Some((v, d)) = q.pop_front() {
        if d > dp[v].0 {
            continue;
        }
        for &(u, c) in graph[v].iter() {
            let d = d + c;
            if dp[u].0 > d {
                dp[u] = (d, v);
                if c == 0 {
                    q.push_front((u, d));
                } else {
                    q.push_back((u, d));
                }
            }
        }
    }
    if dp[n].0 == n + 1 {
        println!("-1");
        return;
    }
    let mut ans = vec![];
    let mut pos = n;
    while pos != 0 {
        if pos <= n {
            ans.push(pos);
        }
        pos = dp[pos].1;
    }
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.len()));
    for a in ans.iter().rev() {
        s.push_str(&format!("{} ", *a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
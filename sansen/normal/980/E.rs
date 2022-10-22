// ---------- begin SegmentTree Point update Range query ----------
mod segment_tree {
    pub struct PURQ<T: Clone, F: Fn(T, T) -> T> {
        n: usize,
        a: Vec<T>,
        id: T,
        op: F,
    }
    #[allow(dead_code)]
    impl<T: Clone, F: Fn(T, T) -> T> PURQ<T, F> {
        pub fn new(n: usize, id: T, op: F) -> PURQ<T, F> {
            let mut k = 1;
            while k < n {
                k *= 2;
            }
            PURQ {
                n: k,
                a: vec![id.clone(); 2 * k],
                id: id,
                op: op,
            }
        }
        pub fn update(&mut self, x: usize, v: T) {
            let mut k = self.n + x;
            let a = &mut self.a;
            a[k] = v;
            k >>= 1;
            while k > 0 {
                a[k] = (self.op)(a[2 * k].clone(), a[2 * k + 1].clone());
                k >>= 1;
            }
        }
        pub fn update_tmp(&mut self, x: usize, v: T) {
            self.a[x + self.n] = v;
        }
        pub fn update_all(&mut self) {
            for k in (1..(self.n)).rev() {
                self.a[k] = (self.op)(self.a[2 * k].clone(), self.a[2 * k + 1].clone());
            }
        }
        pub fn find(&self, mut l: usize, mut r: usize) -> T {
            let mut p = self.id.clone();
            let mut q = self.id.clone();
            l += self.n;
            r += self.n;
            while l < r {
                if (l & 1) == 1 {
                    p = (self.op)(p, self.a[l].clone());
                    l += 1;
                }
                if (r & 1) == 1 {
                    r -= 1;
                    q = (self.op)(self.a[r].clone(), q);
                }
                l >>= 1;
                r >>= 1;
            }
            (self.op)(p, q)
        }
    }
}
// ---------- end SegmentTree Point update Range query ----------
// ---------- begin Heavy-Light decomposition ----------
struct HLD {
    graph: Vec<Vec<usize>>,
    path_root: Vec<usize>,
    path_parent: Vec<usize>,
    left: Vec<usize>,
    right: Vec<usize>,
}

impl HLD {
    fn new(n: usize) -> Self {
        HLD {
            graph: vec![vec![]; n],
            path_root: vec![],
            path_parent: vec![],
            left: vec![],
            right: vec![],
        }
    }
    fn add_edge(&mut self, a: usize, b: usize) {
        self.graph[a].push(b);
        self.graph[b].push(a);
    }
    fn build(&mut self, root: usize) {
        let mut q = vec![];
        let mut stack = vec![(root, root)];
        let graph = &mut self.graph;
        while let Some((v, p)) = stack.pop() {
            q.push(v);
            if let Some(k) = graph[v].iter().position(|u| *u == p) {
                graph[v].swap_remove(k);
            }
            for &u in graph[v].iter() {
                stack.push((u, v));
            }
        }
        let n = graph.len();
        let mut size = vec![1; n];
        for &v in q.iter().rev() {
            let child = &mut graph[v];
            if child.is_empty() {
                continue;
            }
            let mut max = (0, 0);
            for (i, &u) in child.iter().enumerate() {
                size[v] += size[u];
                max = std::cmp::max(max, (size[u], i));
            }
            child.swap(0, max.1);
        }
        let mut path_root = vec![root; n];
        let mut path_parent = vec![root; n];
        let mut left = vec![0; n];
        let mut right = vec![0; n];
        let mut stack = vec![(root, false)];
        let mut k = 0;
        while let Some((v, end)) = stack.pop() {
            if end {
                right[v] = k;
                continue;
            }
            left[v] = k;
            k += 1;
            stack.push((v, true));
            let child = &graph[v];
            if child.is_empty() {
                continue;
            }
            for &u in child.iter().skip(1) {
                path_root[u] = u;
                path_parent[u] = v;
                stack.push((u, false));
            }
            let u = child[0];
            path_root[u] = path_root[v];
            path_parent[u] = path_parent[v];
            stack.push((u, false));
        }
        self.path_root = path_root;
        self.path_parent = path_parent;
        self.left = left;
        self.right = right;
    }
    #[allow(dead_code)]
    fn sub_tree(&self, v: usize) -> (usize, usize) {
        (self.left[v], self.right[v])
    }
    #[allow(dead_code)]
    fn path(&self, v: usize, u: usize) -> Vec<(usize, usize)> {
        let path = &self.path_root;
        let parent = &self.path_parent;
        let index = &self.left;
        let mut x = v;
        let mut y = u;
        let mut ans = vec![];
        while path[x] != path[y] {
            if index[x] < index[y] {
                let p = path[y];
                ans.push((index[p], index[y] + 1));
                y = parent[y];
            } else {
                let p = path[x];
                ans.push((index[p], index[x] + 1));
                x = parent[x];
            }
        }
        ans.push((std::cmp::min(index[x], index[y]), std::cmp::max(index[x], index[y]) + 1));
        ans
    }
}
// ---------- end Heavy-Light decomposition ----------
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
        k: usize,
        e: [(usize1, usize1); n - 1],
    }
    let mut hld = HLD::new(n);
    for (a, b) in e {
        hld.add_edge(a, b);
    }
    hld.build(n - 1);
    let mut seg = segment_tree::PURQ::new(n, 0, |a, b| a + b);
    for i in 0..n {
        seg.update_tmp(i, 1);
    }
    seg.update_all();
    let mut one = vec![true; n];
    let mut ans = vec![];
    let mut free = n - k;
    for i in (0..n).rev() {
        let path = hld.path(n - 1, i);
        let mut sum = 0;
        for &(l, r) in path.iter() {
            sum += seg.find(l, r);
        }
        if sum <= free {
            for &(l, r) in path.iter() {
                for k in (l..r).rev() {
                    if one[k] {
                        seg.update(k, 0);
                        one[k] = false;
                        free -= 1;
                    } else {
                        break;
                    }
                }
            }
        } else {
            ans.push(i);
        }
    }
    ans.reverse();
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
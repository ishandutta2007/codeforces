// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
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
// ---------- begin SCC ----------
pub struct SCC {
    size: usize,
    edge: Vec<(u32, u32)>,
}

impl SCC {
    pub fn new(size: usize) -> Self {
        assert!(size <= 10usize.pow(8));
        SCC { size, edge: vec![] }
    }
    pub fn add_edge(&mut self, a: usize, b: usize) {
        assert!(a < self.size && b < self.size);
        self.edge.push((a as u32, b as u32));
    }
    pub fn build(&self) -> (usize, Vec<usize>) {
        let size = self.size;
        let mut start = vec![0u32; size + 1];
        self.edge.iter().for_each(|e| start[e.0 as usize + 1] += 1);
        for i in 1..=size {
            start[i] += start[i - 1];
        }
        let mut buf = vec![0; self.edge.len()];
        for &(a, b) in self.edge.iter() {
            let po = &mut start[a as usize];
            buf[*po as usize] = b;
            *po += 1;
        }
        let mut s = 0usize;
        let mut neighbor = start.into_iter().take(size).map(|t| {
            let t = t as usize;
            let it = buf[s..t].iter().map(|p| *p as usize);
            s = t;
            it
        }).collect::<Vec<_>>();
        let mut ord = vec![size; size];
        let mut assigned = vec![false; size];
        let mut stack_s = vec![];
        let mut stack_p = vec![];
        let mut call = vec![];
        let mut now_ord = 0;
        let mut res = vec![0; size];
        let mut id = 0;
        enum Operation {
            Call(usize),
            Iter(usize),
            Eval(usize),
        }
        for i in 0..size {
            if ord[i] != size {
                continue;
            }
            call.push(Operation::Call(i));
            while let Some(op) = call.pop() {
                match op {
                    Operation::Call(v) => {
                        ord[v] = now_ord;
                        now_ord += 1;
                        stack_s.push(v);
                        stack_p.push(v);
                        call.push(Operation::Eval(v));
                        call.push(Operation::Iter(v));
                    },
                    Operation::Iter(v) => {
                        let it = &mut neighbor[v];
                        while let Some(u) = it.next() {
                            if ord[u] == size {
                                call.push(Operation::Iter(v));
                                call.push(Operation::Call(u));
                                break;
                            } else if !assigned[u] {
                                while ord[*stack_p.last().unwrap()] > ord[u] {
                                    stack_p.pop();
                                }
                            }
                        }
                    },
                    Operation::Eval(v) => {
                        if *stack_p.last().unwrap() == v {
                            while let Some(u) = stack_s.pop() {
                                res[u] = id;
                                assigned[u] = true;
                                if u == v {
                                    break;
                                }
                            }
                            stack_p.pop();
                            id += 1;
                        }
                    },
                }
            }
        }
        res.iter_mut().for_each(|v| *v = id - 1 - *v);
        (id, res)
    }
}
// ---------- end SCC ----------
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

fn run() {
    input! {
        h: usize,
        w: usize,
        s: [bytes; h],
        a: [usize; w],
    }
    let pos = |x: usize, y: usize| -> usize {
        assert!(x < h && y < w);
        x * w + y
    };
    let mut scc = SCC::new(h * w);
    let mut edge = vec![];
    for i in 0..h {
        for j in 0..w {
            if s[i][j] == b'.' {
                continue;
            }
            let src = pos(i, j);
            if i + 1 < h && s[i + 1][j] == b'#' {
                let dst = pos(i + 1, j);
                scc.add_edge(src, dst);
                scc.add_edge(dst, src);
            }
            if j + 1 < w && s[i][j + 1] == b'#' {
                let dst = pos(i, j + 1);
                scc.add_edge(src, dst);
                scc.add_edge(dst, src);
            }
            let mut x = i + 1;
            while x < h && s[x][j] == b'.' {
                if j > 0 && s[x][j - 1] == b'#' {
                    let dst = pos(x, j - 1);
                    edge.push((src, dst));
                    scc.add_edge(src, dst);
                }
                if j + 1 < w && s[x][j + 1] == b'#' {
                    let dst = pos(x, j + 1);
                    edge.push((src, dst));
                    scc.add_edge(src, dst);
                }
                x += 1;
            }
            if x < h {
                let dst = pos(x, j);
                edge.push((src, dst));
                scc.add_edge(src, dst);
            }
        }
    }
    let (len, id) = scc.build();
    edge = edge.into_iter().filter_map(|(s, t)| {
        let s = id[s];
        let t = id[t];
        if s != t {
            Some((s, t))
        } else {
            None
        }
    }).collect();
    edge.sort();
    edge.dedup();
    let mut g = vec![vec![]; len];
    for (s, t) in edge {
        g[s].push(t);
    }
    let mut left = vec![w; len];
    for j in 0..w {
        for i in 0..h {
            if s[i][j] == b'#' && left[id[pos(i, j)]].chmin(j) {
                let mut dfs = vec![id[pos(i, j)]];
                while let Some(v) = dfs.pop() {
                    for &u in g[v].iter() {
                        if left[u].chmin(j) {
                            dfs.push(u);
                        }
                    }
                }
            }
        }
    }
    let mut right = vec![0; len];
    for j in (0..w).rev() {
        for i in 0..h {
            if s[i][j] == b'#' && right[id[pos(i, j)]].chmax(j + 1) {
                let mut dfs = vec![id[pos(i, j)]];
                while let Some(v) = dfs.pop() {
                    for &u in g[v].iter() {
                        if right[u].chmax(j + 1) {
                            dfs.push(u);
                        }
                    }
                }
            }
        }
    }
    let mut range = vec![];
    for (j, a) in a.iter().enumerate() {
        if *a == 0 {
            continue;
        }
        let i = (0..h).rev().filter(|k| s[*k][j] == b'#').nth(*a - 1).unwrap();
        let v = id[pos(i, j)];
        range.push((left[v] + 1, right[v]));
    }
    range.sort_by_key(|p| p.1);
    let mut ans = 0;
    let mut max = 0;
    for (l, r) in range {
        if max < l {
            ans += 1;
            max = r;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
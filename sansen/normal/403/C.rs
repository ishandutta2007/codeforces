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
        let mut buf = vec![0u32; self.edge.len()];
        for &(a, b) in self.edge.iter() {
            let po = &mut start[a as usize];
            buf[*po as usize] = b;
            *po += 1;
        }
        let mut s = 0usize;
        let neighbor = start[..size].iter().map(|t| {
            let t = *t as usize;
            let it = buf[s..t].iter().map(|p| *p as usize);
            s = t;
            it
        }).collect::<Vec<_>>();
        struct Graph<I> {
            neighbor: Vec<I>,
            ord: Vec<usize>,
            assigned: Vec<bool>,
            stack_s: Vec<usize>,
            stack_p: Vec<usize>,
            cnt: usize,
            id: usize,
            res: Vec<usize>,
        }
        impl<I: Iterator<Item = usize>> Graph<I> {
            fn dfs(&mut self, v: usize) {
                self.ord[v] = self.cnt;
                self.cnt += 1;
                self.stack_s.push(v);
                self.stack_p.push(v);
                while let Some(u) = self.neighbor[v].next() {
                    if self.ord[u] == !0 {
                        self.dfs(u);
                    } else if !self.assigned[u] {
                        while self.ord[*self.stack_p.last().unwrap()] > self.ord[u] {
                            self.stack_p.pop();
                        }
                    }
                }
                if *self.stack_p.last().unwrap() == v {
                    while let Some(u) = self.stack_s.pop() {
                        self.res[u] = self.id;
                        self.assigned[u] = true;
                        if u == v {
                            break;
                        }
                    }
                    self.stack_p.pop();
                    self.id += 1;
                }
            }
        }
        let mut g = Graph {
            neighbor: neighbor,
            ord: vec![!0; size],
            assigned: vec![false; size],
            stack_s: vec![],
            stack_p: vec![],
            id: 0,
            cnt: 0,
            res: vec![0; size],
        };
        for i in 0..size {
            if g.ord[i] == !0 {
                g.dfs(i);
            }
        }
        let Graph { mut res, id, .. } = g;
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

fn run() {
    input! {
        n: usize,
        a: [[u8; n]; n],
    }
    let mut scc = SCC::new(n);
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            if *a > 0 {
                scc.add_edge(i, j)
            }
        }
    }
    if scc.build().0 == 1 {
        println!("YES");
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}
// ---------- begin Strongly Connected Components ----------
struct SCC {
    graph: Vec<Vec<usize>>,
    inv_graph: Vec<Vec<usize>>,
    id: Vec<usize>,
}

impl SCC {
    pub fn new(size: usize) -> SCC {
        SCC {
            graph: vec![vec![]; size],
            inv_graph: vec![vec![]; size],
            id: Vec::with_capacity(size),
        }
    }
    pub fn add_edge(&mut self, from: usize, to: usize) {
        self.graph[from].push(to);
        self.inv_graph[to].push(from);
    }
    pub fn build(&mut self) {
        let size = self.graph.len();
        let mut visited = vec![false; size];
        let mut q = vec![];
        let mut stack = vec![];
        for v in 0..size {
            if visited[v] {
                continue;
            }
            stack.clear();
            stack.push((v, 0));
            while let Some((v, s)) = stack.pop() {
                visited[v] = true;
                let mut finish = true;
                for (i, &u) in self.graph[v][s..].iter().enumerate() {
                    if !visited[u] {
                        finish = false;
                        stack.push((v, s + i + 1));
                        stack.push((u, 0));
                        break;
                    }
                }
                if finish {
                    q.push(v);
                }
            }
        }
        self.id.clear();
        self.id.resize(size, size);
        let mut counter = 0;
        let mut stack = vec![];
        for &v in q.iter().rev() {
            if self.id[v] < size {
                continue;
            }
            self.id[v] = counter;
            stack.clear();
            stack.push(v);
            while let Some(v) = stack.pop() {
                self.id[v] = counter;
                for &u in self.inv_graph[v].iter() {
                    if self.id[u] == size {
                        self.id[u] = counter;
                        stack.push(u);
                    }
                }
            }
            counter += 1;
        }
    }
    pub fn get_array(&self) -> Vec<usize> {
        self.id.clone()
    }
}
// ---------- end Strongly Connected Components ----------
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
        p: [usize1; n],
        q: [usize1; n],
    }
    let mut scc = SCC::new(n);
    for i in 1..n {
        scc.add_edge(p[i - 1], p[i]);
        scc.add_edge(q[i - 1], q[i]);
    }
    scc.build();
    let a = scc.get_array();
    if a.iter().max().unwrap() + 1 < k {
        println!("NO");
        return;
    }
    let mut out = String::new();
    let mut op = vec![];
    for i in 0..26 {
        let c = ('a' as u8 + i) as char;
        op.push(c);
    }
    for i in 0..n {
        let k = if a[i] >= k {k - 1} else {a[i]};
        out.push(op[k]);
    }
    println!("YES\n{}", out);
}

fn main() {
    run();
}
// ---------- begin Strongly Connected Components ----------
struct SCC {
    size: usize,
    edge: Vec<(usize, usize)>,
    id: Vec<usize>,
    scc_edge: Vec<(usize, usize)>,
}

impl SCC {
    pub fn new(size: usize) -> Self {
        SCC {
            size: size,
            edge: vec![],
            id: Vec::with_capacity(size),
            scc_edge: vec![],
        }
    } 
    pub fn add_edge(&mut self, from: usize, to: usize) {
        assert!(from < self.size && to < self.size);
        self.edge.push((from, to));
    }
    fn build_graph<'a>(&self, buf: &'a mut [usize], cnt: &[usize], inv: bool) -> Vec<&'a mut [usize]> {
        let size = self.size;
        let mut index = vec![0; self.size];
        for e in self.edge.iter() {
            let (f, t) = if inv { (e.1, e.0) } else { *e };
            buf[self.edge.len() - cnt[f] + index[f]] = t;
            index[f] += 1;
        }
        let mut ans = Vec::with_capacity(size);
        let mut buf = Some(buf);
        for i in 0..size {
            let len = cnt[i] - cnt[i + 1];
            let x = buf.take().unwrap();
            let (x, y) = x.split_at_mut(len);
            ans.push(x);
            buf = Some(y);
        }
        ans
    }
    fn dfs1(&self, buf: &mut [usize], cnt: &[usize], q: &mut Vec<usize>) {
        let size = self.size;
        let graph = self.build_graph(buf, cnt, false);
        let mut visited = vec![false; size];
        let mut stack = vec![];
        for v in 0..size {
            if visited[v] {
                continue;
            }
            stack.clear();
            visited[v] = true;
            stack.push((v, graph[v].iter()));
            while let Some((v, mut it)) = stack.pop() {
                let mut finish = true;
                while let Some(&u) = it.next() {
                    if !visited[u] {
                        visited[u] = true;
                        finish = false;
                        stack.push((v, it));
                        stack.push((u, graph[u].iter()));
                        break;
                    }
                }
                if finish {
                    q.push(v);
                }
            }
        }
    }
    fn dfs2(&mut self, buf: &mut [usize], cnt: &[usize], q: &[usize]) {
        let size = self.size;
        let inv_graph = self.build_graph(buf, cnt, true);
        self.id.clear();
        self.id.resize(size, size);
        self.scc_edge.clear();
        let mut counter = 0;
        let mut stack = vec![];
        let mut sink = vec![];
        let mut used = vec![false; self.size];
        for &v in q.iter().rev() {
            if self.id[v] < size {
                continue;
            }
            self.id[v] = counter;
            stack.push(v);
            while let Some(v) = stack.pop() {
                self.id[v] = counter;
                for &u in inv_graph[v].iter() {
                    if self.id[u] == size {
                        self.id[u] = counter;
                        stack.push(u);
                    } else if self.id[u] < counter && !used[self.id[u]] {
                        used[self.id[u]] = true;
                        sink.push(self.id[u]);
                        self.scc_edge.push((self.id[u], counter));
                    }
                }
            }
            for &u in &sink {
                used[u] = false;
            }
            sink.clear();
            counter += 1;
        }
    }
    pub fn build(&mut self) {
        let size = self.size;
        let mut cnt = vec![0; size + 1];
        let mut inv_cnt = vec![0; size + 1];
        for e in self.edge.iter() {
            cnt[e.0] += 1;
            inv_cnt[e.1] += 1;
        }
        for i in (0..size).rev() {
            cnt[i] += cnt[i + 1];
            inv_cnt[i] += inv_cnt[i + 1];
        }
        let mut buf = vec![0; self.edge.len()];
        let mut q = Vec::with_capacity(size);
        self.dfs1(&mut buf, &cnt, &mut q);
        self.dfs2(&mut buf, &inv_cnt, &q);
    }
    pub fn get_array(&self) -> Vec<usize> {
        self.id.clone()
    }
    pub fn get_edge(&self) -> Vec<(usize, usize)> {
        self.scc_edge.clone()
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
        m: usize,
        d: usize,
        e: [(usize1, usize1); m],
        s: [chars; n],
    }
    let mut scc = SCC::new(d * n);
    for &(s, t) in e.iter() {
        for i in 0..d {
            let s = i * n + s;
            let t = (i + 1) % d * n + t;
            scc.add_edge(s, t);
        }
    }
    scc.build();
    let id = scc.get_array();
    let e = scc.get_edge();
    let len = *id.iter().max().unwrap() + 1;
    let mut cnt = vec![0; len];
    let mut used = vec![false; len];
    for v in 0..n {
        for (i, &c) in s[v].iter().enumerate() {
            let u = id[i * n + v];
            if c == '1' && !used[u] {
                cnt[u] += 1;
                used[u] = true;
            }
        }
        for i in 0..d {
            let u = id[i * n + v];
            used[u] = false;
        }
    }
    let mut ans = cnt[id[0 * n + 0]];
    let mut valid = vec![false; len];
    valid[id[0 * n + 0]] = true;
    let mut dp = vec![0; len];
    for &(s, t) in e.iter() {
        if valid[s] {
            dp[t] = std::cmp::max(dp[t], dp[s] + cnt[s]);
            valid[t] |= valid[s];
            ans = std::cmp::max(ans, dp[t] + cnt[t]);
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
// ---------- begin Strongly Connected Components ----------
struct SCC {
    size: usize,
    edge: Vec<(u32, u32)>,
    id: Vec<usize>,
}

impl SCC {
    pub fn new(size: usize) -> Self {
        SCC {
            size: size,
            edge: vec![],
            id: Vec::with_capacity(size),
        }
    }
    pub fn add_edge(&mut self, from: usize, to: usize) {
        assert!(from < self.size && to < self.size);
        self.edge.push((from as u32, to as u32));
    }
    fn fill_buffer(&self, buf: &mut [u32], cnt: &[u32], inv: bool) {
        let mut index = vec![0; self.size];
        let mut sum = 0;
        for (index, c) in index.iter_mut().zip(cnt.iter()) {
            *index = sum;
            sum += *c;
        }
        for e in self.edge.iter() {
            let (f, t) = if inv {
                (e.1 as usize, e.0)
            } else {
                (e.0 as usize, e.1)
            };
            buf[index[f] as usize] = t;
            index[f] += 1;
        }
    }
    fn build_graph<'a>(&self, buf: &'a mut [u32], cnt: &'a [u32], inv: bool) -> Vec<&'a mut [u32]> {
        let size = self.size;
        self.fill_buffer(buf, cnt, inv);
        let mut buf = Some(buf);
        let mut ans = Vec::with_capacity(size);
        for c in cnt.iter() {
            let len = *c as usize;
            let x = buf.take().unwrap();
            let (x, y) = x.split_at_mut(len);
            ans.push(x);
            buf = Some(y);
        }
        ans
    }
    fn dfs1(&self, buf: &mut [u32], cnt: &[u32], q: &mut Vec<u32>) {
        let size = self.size;
        let graph = self.build_graph(buf, cnt, false);
        let mut visited = vec![false; size];
        let mut stack = vec![];
        for v in 0..size {
            if visited[v] {
                continue;
            }
            visited[v] = true;
            stack.push((v, graph[v].iter()));
            while let Some((v, mut it)) = stack.pop() {
                let mut finish = true;
                while let Some(&u) = it.next() {
                    let u = u as usize;
                    if !visited[u] {
                        visited[u] = true;
                        finish = false;
                        stack.push((v, it));
                        stack.push((u, graph[u].iter()));
                        break;
                    }
                }
                if finish {
                    q.push(v as u32);
                }
            }
        }
    }
    fn dfs2(&mut self, buf: &mut [u32], cnt: &[u32], q: &[u32]) {
        let size = self.size;
        let inv_graph = self.build_graph(buf, cnt, true);
        self.id.clear();
        self.id.resize(size, size);
        let mut counter = 0;
        let mut stack = vec![];
        for &v in q.iter().rev() {
            let v = v as usize;
            if self.id[v] < size {
                continue;
            }
            stack.push(v);
            while let Some(v) = stack.pop() {
                self.id[v] = counter;
                for &u in inv_graph[v].iter() {
                    let u = u as usize;
                    if self.id[u] == size {
                        self.id[u] = counter;
                        stack.push(u);
                    }
                }
            }
            counter += 1;
        }
    }
    pub fn build(&mut self) {
        let size = self.size;
        let mut cnt = vec![0; size];
        let mut inv_cnt = vec![0; size];
        for e in self.edge.iter() {
            cnt[e.0 as usize] += 1;
            inv_cnt[e.1 as usize] += 1;
        }
        let mut buf = vec![0; self.edge.len()];
        let buf = buf.as_mut_slice();
        let mut q = Vec::with_capacity(size);
        self.dfs1(buf, &cnt, &mut q);
        self.dfs2(buf, &inv_cnt, &q);
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
        h: usize,
        w: usize,
        a: [[u32; w]; h],
    }
    let mut b = a.iter().flatten().cloned().collect::<Vec<_>>();
    b.sort();
    b.dedup();
    let mut g = vec![vec![]; b.len()];
    for (i, a) in a.iter().enumerate() {
        for (j, a) in a.iter().enumerate() {
            let a = b.binary_search(a).unwrap();
            g[a].push((i, j));
        }
    }
    let mut edge = vec![];
    let mut row = vec![None; h];
    let mut col = vec![None; w];
    for g in g {
        let mut x = std::collections::BTreeMap::new();
        let mut y = std::collections::BTreeMap::new();
        for &(a, b) in g.iter() {
            let v = a * w + b;
            for (map, x) in [(&mut x, a), (&mut y, b)].iter_mut() {
                if let Some(&k) = map.get(x) {
                    edge.push((k, v));
                    edge.push((v, k));
                }
                map.insert(*x, v);
            }
        }
        for (row, x) in [(&mut row, x), (&mut col, y)].iter_mut() {
            for (&x, &k) in x.iter() {
                if let Some(u) = row[x] {
                    edge.push((k, u));
                }
                row[x] = Some(k);
            }
        }
    }
    let mut scc = SCC::new(h * w);
    for &(a, b) in edge.iter() {
        scc.add_edge(a, b);
    }
    scc.build();
    let id = scc.get_array();
    let len = *id.iter().max().unwrap() + 1;
    let mut g = vec![vec![]; len];
    for &(a, b) in edge.iter() {
        let a = id[a];
        let b = id[b];
        if a != b {
            g[a].push(b);
        }
    }
    let mut ans = vec![1; len];
    for v in (0..len).rev() {
        let mut val = 1;
        for &u in g[v].iter() {
            val = std::cmp::max(val, ans[u] + 1);
        }
        ans[v] = val;
    }
    let mut s = String::new();
    for i in 0..h {
        for j in 0..w {
            let v = ans[id[i * w + j]];
            s.push_str(&format!("{} ", v));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
}

fn main() {
    run();
}
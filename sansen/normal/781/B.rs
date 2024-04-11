// ---------- begin Strongly Connected Components ----------
struct SCC {
    size: usize,
    edge: Vec<(usize, usize)>,
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
                for &u in inv_graph[v].iter() {
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
}
// ---------- end Strongly Connected Components ----------
// ---------- begin 2-SAT ----------
struct SAT2 {
    size: usize,
    scc: SCC,
}

impl SAT2 {
    fn new(size: usize) -> Self {
        SAT2 {
            size: size,
            scc: SCC::new(2 * size),
        }
    }
    fn add(&mut self, a: usize, b: usize) {
        let size = self.size;
        let (x, ix) = if a >= size {
            (!a + size, !a)
        } else {
            (a, a + size)
        };
        let (y, iy) = if b >= size {
            (!b + size, !b)
        } else {
            (b, b + size)
        };
        self.scc.add_edge(ix, y);
        self.scc.add_edge(iy, x);
    }
    fn solve(&mut self) -> Option<Vec<bool>> {
        self.scc.build();
        let id = self.scc.get_array();
        let mut ans = vec![];
        for i in 0..self.size {
            if id[i] == id[i + self.size] {
                return None;
            } else if id[i] < id[i + self.size] {
                ans.push(false);
            } else {
                ans.push(true);
            }
        }
        Some(ans)
    }
}
// ---------- end 2-SAT ----------
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

use std::io::Write;

// X_i : i first name
// i.first == j.first => !X_i or !X_j
// i.first == j.second => !X_i or X_j
// i.second == j.second => X_i or X_j
//
// i second ifirstfirst
// i.second == j.first => X_i or !X_j
//
// !i.first && j.first

fn run() {
    input! {
        n: usize,
        p: [(bytes, bytes); n],
    }
    let p: Vec<(Vec<u8>, Vec<u8>)> = p.into_iter().map(|(a, b)| {
        let a = a.iter().cloned().take(3).collect::<Vec<_>>();
        let b = a.iter().take(2).chain(b.iter().take(1)).cloned().collect::<Vec<_>>();
        (a, b)
    }).collect();
    let mut sat = SAT2::new(n);
    type Set = std::collections::BTreeSet<usize>;
    let mut map1 = std::collections::BTreeMap::<Vec<u8>, Set>::new();
    let mut map2 = std::collections::BTreeMap::<Vec<u8>, Set>::new();
    for (i, p) in p.iter().enumerate() {
        let a = &p.0;
        let b = &p.1;
        if let Some(v) = map1.get(a) {
            for &k in v.iter() {
                sat.add(!i, !k);
                sat.add(i, !k);
                sat.add(!i, k);
            }
        }
        if let Some(v) = map2.get(a) {
            for &k in v.iter() {
                sat.add(!i, k);
            }
        }
        if let Some(v) = map1.get(b) {
            for &k in v.iter() {
                sat.add(i, !k);
            }
        }
        if let Some(v) = map2.get(b) {
            for &k in v.iter() {
                sat.add(i, k);
            }
        }
        map1.entry(a.clone()).or_insert(Set::new()).insert(i);
        map2.entry(b.clone()).or_insert(Set::new()).insert(i);
    }
    if let Some(b) = sat.solve() {
        let out = std::io::stdout();
        let mut out = std::io::BufWriter::new(out.lock());
        writeln!(out, "YES").ok();
        for i in 0..n {
            if b[i] {
                for p in p[i].0.iter() {
                    write!(out, "{}", *p as char).ok();
                }
            } else {
                for p in p[i].1.iter() {
                    write!(out, "{}", *p as char).ok();
                }
            }
            writeln!(out).ok();
        }
    } else {
        println!("NO");
    }
}

fn main() {
    run();
}
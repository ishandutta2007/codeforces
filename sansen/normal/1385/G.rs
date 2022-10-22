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
// ---------- begin scannner ----------
#[allow(dead_code)]
mod scanner {
    use std::str::FromStr;
    use std::str::SplitWhitespace;
    use std::io::Read;
    use std;
    pub struct Scanner<'a> {
        it: SplitWhitespace<'a>
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace()
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            match self.it.next().unwrap().parse::<T>() {
                Ok(v) => v,
                _ => panic!("Scanner error")
            }
        }
        pub fn next_chars(&mut self) -> Vec<char> {
            self.next::<String>().chars().collect()
        }
        pub fn next_vec<T: FromStr>(&mut self, len: usize) -> Vec<T> {
            (0..len).map(|_| self.next()).collect()
        }
    }
    pub fn read_string() -> String {
        let mut s = String::new();
        std::io::stdin().read_to_string(&mut s).unwrap();
        s
    }
}
// ---------- end scannner ----------

use std::io::Write;

fn main() {
    let sc = scanner::read_string();
    let mut sc = scanner::Scanner::new(&sc);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<std::io::StdoutLock>) {
    let t: usize = sc.next();
    for _ in 0..t {
        let n: usize = sc.next();
        let mut a = vec![vec![]; n];
        for k in 0..2 {
            for i in 0..n {
                let v = sc.next::<usize>() - 1;
                a[v].push((i, k));
            }
        }
        if a.iter().any(|a| a.len() != 2) {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut solver = SAT2::new(n);
        let mut g = vec![vec![]; n];
        for a in a.iter() {
            let (f, t) = (a[0].0, a[1].0);
            g[f].push(t);
            g[t].push(f);
            let x = if a[0].1 == 0 {
                a[0].0
            } else {
                !a[0].0
            };
            let y = if a[1].1 == 0 {
                a[1].0
            } else {
                !a[1].0
            };
            solver.add(x, y);
            solver.add(!x, !y);
        }
        if let Some(mut ans) = solver.solve() {
            let mut used = vec![false; n];
            for i in 0..n {
                if used[i] {
                    continue;
                }
                used[i] = true;
                let mut q = vec![i];
                let mut j = 0;
                while j < q.len() {
                    let v = q[j];
                    j += 1;
                    for &u in g[v].iter() {
                        if !used[u] {
                            used[u] = true;
                            q.push(u);
                        }
                    }
                }
                let cnt = q.iter().filter(|p| ans[**p]).count();
                if 2 * cnt > q.len() {
                    for &u in q.iter() {
                        ans[u] ^= true;
                    }
                }
            }
            let mut b = vec![];
            for (i, _) in ans.iter().enumerate().filter(|p| *p.1) {
                b.push(i + 1);
            }
            writeln!(out, "{}", b.len()).ok();
            let mut s = String::new();
            for b in b {
                s.push_str(&format!("{} ", b));
            }
            s.pop();
            writeln!(out, "{}", s).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}
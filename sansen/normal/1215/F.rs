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
            id: vec![0; size],
        }
    }
    pub fn add_edge(&mut self, from: usize, to: usize) {
        assert!(from < self.size && to < self.size);
        self.edge.push((from as u32, to as u32));
    }
    fn fill_buffer(&self, buf: &mut [u32], cnt: &[u32]) {
        let mut index = vec![0; self.size];
        let mut sum = 0;
        for (index, c) in index.iter_mut().zip(cnt.iter()) {
            *index = sum;
            sum += *c;
        }
        for &(f, t) in self.edge.iter() {
            let f = f as usize;
            buf[index[f] as usize] = t;
            index[f] += 1;
        }
    }
    fn build_graph<'a>(&self, buf: &'a mut [u32]) -> Vec<&'a mut [u32]> {
        let size = self.size;
        let mut cnt = vec![0; size];
        for e in self.edge.iter() {
            cnt[e.0 as usize] += 1;
        }
        self.fill_buffer(buf, &cnt);
        let mut buf = Some(buf);
        let mut ans = Vec::with_capacity(size);
        for &len in cnt.iter() {
            let len = len as usize;
            let x = buf.take().unwrap();
            let (x, y) = x.split_at_mut(len);
            ans.push(x);
            buf = Some(y);
        }
        ans
    }
    pub fn build(&mut self) {
        let size = self.size;
        let mut buf = vec![0; self.edge.len()];
        let buf = buf.as_mut_slice();
        let graph = self.build_graph(buf);
        let empty = size as u32;
        let mut index = 0;
        let mut ord = vec![empty; size];
        let mut assigned = vec![false; size];
        let mut id = 0;
        let mut stack_s = vec![];
        let mut stack_p = vec![];
        let mut call = vec![];
        for i in 0..size {
            if ord[i] != empty {
                continue;
            }
            enum Operation {
                Call(usize),
                Iterate(usize, usize),
                Eval(usize),
            }
            call.push(Operation::Call(i));
            while let Some(op) = call.pop() {
                match op {
                    Operation::Call(v) => {
                        ord[v] = index;
                        index += 1;
                        stack_s.push(v);
                        stack_p.push(v);
                        call.push(Operation::Eval(v));
                        call.push(Operation::Iterate(v, 0));
                    },
                    Operation::Iterate(v, k) => {
                        for i in k..graph[v].len() {
                            let u = graph[v][i] as usize;
                            if ord[u] == empty {
                                call.push(Operation::Iterate(v, i + 1));
                                call.push(Operation::Call(u));
                                break;
                            } else if !assigned[u] {
                                while let Some(&x) = stack_p.last() {
                                    if ord[x] <= ord[u] {
                                        break;
                                    } else {
                                        stack_p.pop();
                                    }
                                }
                            }
                        }
                    },
                    Operation::Eval(v) => {
                        if *stack_p.last().unwrap() == v {
                            while let Some(u) = stack_s.pop() {
                                assigned[u] = true;
                                self.id[u] = id;
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
        for x in self.id.iter_mut() {
            *x = id - 1 - *x;
        }
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

use std::io::Read;

struct Counter {
    v: usize,
}

impl Counter {
    fn new() -> Self {
        Counter {
            v: 0,
        }
    }
    fn next(&mut self) -> usize {
        self.v += 1;
        self.v - 1
    }
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let p: usize = it.next().unwrap().parse().unwrap();
    let w: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();
    let counter = &mut Counter::new();
    let mut up = Vec::with_capacity(w + 1);
    for _ in 0..=w {
        up.push(counter.next());
    }
    let mut index = Vec::with_capacity(p);
    for _ in 0..p {
        index.push(counter.next());
    }
    let sat = &mut SAT2::new(up.len() + index.len());
    for i in 0..w {
        sat.add(!up[i], up[i + 1]);
    }
    for _ in 0..n {
        let x: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        let y: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        sat.add(index[x], index[y]);
    }
    let mut range = Vec::with_capacity(p);
    for i in 0..p {
        let v = index[i];
        let l: usize = it.next().unwrap().parse::<usize>().unwrap();
        let r: usize = it.next().unwrap().parse::<usize>().unwrap();
        range.push((l, r));
        sat.add(!v, !up[l - 1]);
        sat.add(!v, up[r]);
    }
    for _ in 0..m {
        let u: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        let v: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
        sat.add(!index[u], !index[v]);
    }
    if let Some(ans) = sat.solve() {
        let mut radio = vec![];
        let mut l = 0;
        let mut r = w;
        for i in 0..p {
            if ans[index[i]] {
                radio.push(i + 1);
                l = std::cmp::max(l, range[i].0);
                r = std::cmp::min(r, range[i].1);
            }
        }
        assert!(l <= r);
        let power = r;
        let mut out = String::new();
        out.push_str(&format!("{} {}\n", radio.len(), power));
        for a in radio {
            out.push_str(&format!("{} ", a));
        }
        out.pop();
        println!("{}", out);
    } else {
        println!("-1");
    }
}

fn main() {
    run();
}
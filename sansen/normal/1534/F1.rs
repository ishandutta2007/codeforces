fn main() {
    input! {
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    let pos = |x: usize, y: usize| x * w + y;
    let mut edge = vec![];
    for i in 0..h {
        for j in 0..w {
            if s[i][j] == b'.' {
                continue;
            }
            for &(dx, dy) in [(1, 0), (0, 1), (!0, 0), (0, !0)].iter() {
                let x = i + dx;
                let y = j + dy;
                if x < h && y < w && s[x][y] == b'#' {
                    edge.push((pos(i, j), pos(x, y)));
                }
            }
            let mut x = i + 1;
            while x < h && s[x][j] == b'.' {
                for &(dx, dy) in [(1, 0), (0, 1), (0, !0)].iter() {
                    let x = x + dx;
                    let y = j + dy;
                    if x < h && y < w && s[x][y] == b'#' {
                        edge.push((pos(i, j), pos(x, y)));
                    }
                }
                x += 1;
            }
        }
    }
    let graph = CSR::new(h * w, edge.iter().cloned());
    let (len, id) = strongly_connected_components(h * w, |v| graph.list(v));
    let mut touch = vec![false; len];
    for i in 0..(h * w) {
        if s[i / w][i % w] == b'#' {
            touch[id[i]] = true;
        }
    }
    for e in edge.iter() {
        if id[e.0] != id[e.1] {
            touch[id[e.1]] = false;
        }
    }
    let ans = touch.into_iter().filter(|v| *v).count();
    println!("{}", ans);
}


// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- begin scc ----------
pub fn strongly_connected_components<G, I>(size: usize, graph: G) -> (usize, Vec<usize>)
where
    G: Fn(usize) -> I,
    I: Iterator<Item = usize>,
{
    let mut ord = vec![0; size];
    let mut res = vec![0; size];
    let mut vertex = vec![];
    let mut dfs = vec![];
    let mut id = 0;
    for s in 0..size {
        if ord[s] > 0 {
            continue;
        }
        vertex.push(s);
        ord[s] = vertex.len();
        dfs.push((s, graph(s)));
        while let Some((v, mut it)) = dfs.pop() {
            (|| {
                while let Some(u) = it.next() {
                    if ord[u] == 0 {
                        vertex.push(u);
                        ord[u] = vertex.len();
                        dfs.push((v, it));
                        dfs.push((u, graph(u)));
                        return;
                    }
                }
                let low = graph(v).map(|u| ord[u]).min().unwrap_or(ord[v]);
                if low < ord[v] {
                    ord[v] = low;
                    return;
                }
                while let Some(u) = vertex.pop() {
                    ord[u] = !0;
                    res[u] = id;
                    if u == v {
                        break;
                    }
                }
                id += 1;
            })();
        }
    }
    res.iter_mut().for_each(|p| *p = id - 1 - *p);
    (id, res)
}
// ---------- end scc ----------
// ---------- begin CSR ----------
pub struct CSR {
    size: usize,
    pos: Vec<u32>,
    list: Vec<u32>,
}

impl CSR {
    pub fn new<I>(size: usize, it: I) -> Self
    where
        I: Iterator<Item = (usize, usize)> + Clone,
    {
        let mut pos = vec![0; size + 1];
        for (s, t) in it.clone() {
            assert!(s < size && t < size);
            pos[s + 1] += 1;
        }
        for i in 1..=size {
            pos[i] += pos[i - 1];
        }
        let mut x = pos[..size].to_vec();
        let mut list = vec![0; pos[size] as usize];
        for (s, t) in it {
            let x = &mut x[s];
            list[*x as usize] = t as u32;
            *x += 1;
        }
        CSR { size, pos, list }
    }
    pub fn list(&self, v: usize) -> impl Iterator<Item = usize> + '_ {
        assert!(v < self.size);
        let s = self.pos[v] as usize;
        let t = self.pos[v + 1] as usize;
        self.list[s..t].iter().map(|p| *p as usize)
    }
}
// ---------- end CSR ----------
//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            UF {p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, x: usize, y: usize) -> Option<(usize, usize)> {
            let mut x = self.root(x);
            let mut y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
        }
        pub fn parent(&self, x: usize) -> Option<usize> {
            let p = self.p[x];
            if p >= 0 {
                Some(p as usize)
            } else {
                None
            }
        }
        pub fn get_size(&self, x: usize) -> usize {
            let r = self.root(x);
            (-self.p[r]) as usize
        }
    }
}
//---------- end union_find ----------
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

fn run() {
    input! {
        n: usize,
        m: usize,
        p: [(u64, u8); m],
    }
    let mut map = std::collections::BTreeMap::new();
    for (i, &(c, b)) in p.iter().enumerate() {
        map.entry(c).or_insert(vec![]).push((b, i));
    }
    let mut ans = vec![(0, 0); m];
    let mut free = vec![std::collections::VecDeque::new(); n];
    let mut u = union_find::UF::new(n);
    let mut p = 1;
    for (_, mut edge) in map {
        edge.sort();
        for &(b, k) in edge.iter().rev() {
            if b == 0 {
                let r = u.root(p - 1);
                if let Some((a, b)) = free[r].pop_front() {
                    ans[k] = (a, b);
                } else {
                    println!("-1");
                    return;
                }
            } else {
                ans[k] = (p - 1, p);
                let (a, b) = u.unite(p - 1, p).unwrap();
                let mut b = std::mem::take(&mut free[b]);
                free[a].append(&mut b);
                let mut i = 0;
                while free[a].len() < m && i < p - 1 {
                    free[a].push_back((i, p));
                    i += 1;
                }
                p += 1;
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (a, b) in ans {
        writeln!(out, "{} {}", a + 1, b + 1).ok();
    }
}

fn main() {
    run();
}
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
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                return None;
            }
            if self.p[x] > self.p[y] {
                let s = x;
                x = y;
                y = s;
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
            Some((x, y))
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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        m: usize,
        d: usize,
        e: [(usize, usize); m],
    }
    let mut g = vec![vec![]; n + 1];
    let mut u = union_find::UF::new(n + 1);
    for &(a, b) in e.iter() {
        u.unite(a, b);
        g[a].push(b);
        g[b].push(a);
    }
    assert!(u.get_size(1) == n);
    if g[1].len() < d {
        writeln!(out, "NO").ok();
        return;
    }
    u.init();
    let mut cnt = n;
    for &(a, b) in e.iter() {
        if a == 1 || b == 1 {
            continue;
        }
        if u.unite(a, b).is_some() {
            cnt -= 1;
        }
    }
    if cnt > d + 1 {
        writeln!(out, "NO").ok();
        return;
    }
    writeln!(out, "YES").ok();
    let mut uni = union_find::UF::new(n + 1);
    let mut cnt = d;
    let mut ans = vec![];
    for &v in g[1].iter() {
        if !u.same(1, v) {
            assert!(uni.unite(1, v).is_some());
            u.unite(1, v);
            ans.push((1, v));
            cnt -= 1;
        }
    }
    for &v in g[1].iter() {
        if cnt > 0 && !uni.same(1, v) {
            uni.unite(1, v);
            ans.push((1, v));
            cnt -= 1;
        }
    }
    for &(a, b) in e.iter() {
        if a == 1 || b == 1 {
            continue;
        }
        if uni.unite(a, b).is_some() {
            ans.push((a, b));
        }
    }
    for (a, b) in ans {
        writeln!(out, "{} {}", a, b).ok();
    }
}

fn main() {
    run();
}
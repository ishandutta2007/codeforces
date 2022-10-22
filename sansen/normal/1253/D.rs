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

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut u = union_find::UF::new(n);
    let mut l: Vec<usize> = (0..n).collect();
    let mut r: Vec<usize> = (0..n).collect();
    for (a, b) in e {
        if let Some((a, b)) = u.unite(a, b) {
            l[a] = std::cmp::min(l[a], l[b]);
            r[a] = std::cmp::max(r[a], r[b]);
        }
    }
    let mut p = vec![];
    for i in 0..n {
        if u.root(i) == i {
            p.push((l[i], r[i]));
        }
    }
    p.sort();
    let mut ans = 0;
    let mut i = 0;
    while i < p.len() {
        if p[i].1 - p[i].0 + 1 == u.get_size(p[i].0) {
            i += 1;
            continue;
        }
        let l = p[i].0;
        let mut r = p[i].1;
        let mut j = i + 1;
        while r - l + 1 != u.get_size(l) {
            ans += 1;
            u.unite(l, p[j].1);
            r = std::cmp::max(r, p[j].1);
            j += 1;
        }
        i = j;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
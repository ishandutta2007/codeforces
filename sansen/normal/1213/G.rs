//---------- begin union_find ----------
mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    #[allow(dead_code)]
    impl UF {
        pub fn new(n: usize) -> UF {
            UF {p: vec![-1; n] }
        }
        pub fn init(&mut self) {
            for p in self.p.iter_mut() {
                *p = -1;
            }
        }
        pub fn root(&mut self, mut x: usize) -> usize {
            while self.p[x] >= 0 {
                x = self.p[x] as usize;
            }
            x
        }
        pub fn same(&mut self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                return;
            }
            if self.p[x] > self.p[y] {
                let s = x;
                x = y;
                y = s;
            }
            self.p[x] += self.p[y];
            self.p[y] = x as i32;
        }
        pub fn get_size(&mut self, x: usize) -> usize {
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
        e: [(usize1, usize1, u32); n - 1],
        q: [u32; m],
    }
    let mut e = e;
    e.sort_by_key(|e| e.2);
    let mut u = union_find::UF::new(n);
    let mut ans = vec![];
    ans.push((0, 0));
    let mut cnt = 0u64;
    let mut i = 0;
    while i < n - 1 {
        let (_, _, c) = e[i];
        while i < n - 1 && e[i].2 == c {
            let (a, b, _) = e[i];
            cnt += u.get_size(a) as u64 * u.get_size(b) as u64;
            u.unite(a, b);
            i += 1;
        }
        ans.push((c, cnt));
    }
    for (i, &q) in q.iter().enumerate() {
        let k = match ans.binary_search(&(q, 1000000000000000u64)) {
            Ok(k) => k - 1,
            Err(k) => k - 1,
        };
        if i > 0 {
            write!(out, " ").unwrap();
        }
        write!(out, "{}", ans[k].1).unwrap();
    }
    write!(out, "\n").unwrap();
}

fn main() {
    run();
}
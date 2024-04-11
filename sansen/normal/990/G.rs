//---------- begin union_find ----------
#[allow(dead_code)]
mod union_find {
    use std;
    pub struct UF {
        parent: Vec<usize>,
        size: Vec<usize>,
        stack: Vec<Option<(usize, usize)>>,
    }
    impl UF {
        pub fn new(n: usize) -> UF {
            let mut u = UF {
                parent: vec![0; n],
                size: vec![1; n],
                stack: vec![],
            };
            u.init();
            u
        }
        pub fn init(&mut self) {
            for (i, p) in self.parent.iter_mut().enumerate() {
                *p = i;
            }
            self.size.clear();
            self.size.resize(self.parent.len(), 1);
            self.stack.clear();
        }
        pub fn root(&mut self, mut x: usize) -> usize {
            while self.parent[x] != x {
                x = self.parent[x];
            }
            x
        }
        pub fn same(&mut self, x: usize, y: usize) -> bool {
            self.root(x) == self.root(y)
        }
        pub fn unite(&mut self, mut x: usize, mut y: usize) -> Option<(usize, usize)> {
            x = self.root(x);
            y = self.root(y);
            if x == y {
                self.stack.push(None);
                return None;
            }
            if self.size[x] < self.size[y] {
                std::mem::swap(&mut x, &mut y);
            }
            self.size[x] += self.size[y];
            self.parent[y] = x;
            self.stack.push(Some((x, y)));
            Some((x, y))
        }
        pub fn undo(&mut self) -> Option<(usize, usize)> {
            self.stack
                .pop()
                .expect("union find undo error: stack is empty")
                .map(|(x, y)| {
                    self.size[x] -= self.size[y];
                    self.parent[y] = y;
                    (x, y)
                })
        }
        pub fn get_size(&mut self, x: usize) -> usize {
            let r = self.root(x);
            self.size[r]
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

fn gcd(a: usize, b: usize) -> usize {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [usize; n],
        e: [(usize1, usize1); n - 1],
    }
    let m = 200_000;
    let mut edge = vec![vec![]; m + 1];
    for (x, y) in e {
        let g = gcd(a[x], a[y]);
        edge[g].push((x, y));
    }
    let mut u = union_find::UF::new(n);
    let mut dp = vec![1u64; n];
    let mut ans = vec![0u64; m + 1];
    for i in 1..=m {
        let mut j = i;
        let mut cnt = 0;
        let mut total = 0u64;
        while let Some(e) = edge.get(j) {
            for &(x, y) in e.iter() {
                cnt += 1;
                let (a, b) = u.unite(x, y).unwrap();
                total += dp[a] * dp[b];
                dp[a] += dp[b];
            }
            j += i;
        }
        ans[i] = total;
        for _ in 0..cnt {
            let (a, _) = u.undo().unwrap();
            dp[a] = 1;
        }
    }
    let mut is_prime = vec![true; m + 1];
    for i in 2..=m {
        if is_prime[i] {
            let mut j = i;
            while let Some(p) = is_prime.get_mut(j) {
                *p = false;
                ans[j / i] -= ans[j];
                j += i;
            }
        }
    }
    for a in a {
        ans[a] += 1;
    }
    for (a, ans) in ans.into_iter().enumerate().filter(|a| a.1 > 0) {
        writeln!(out, "{} {}", a, ans).ok();
    }
}

fn main() {
    run();
}
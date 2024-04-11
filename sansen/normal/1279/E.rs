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

fn add(a: &mut [usize], v: usize) {
    for a in a.iter_mut() {
        *a += v;
    }
}

// n
fn solve2(n: usize, k: u64, a: &[u64]) -> Vec<usize> {
    assert!(n > 0);
    assert!(k < a[n]);
    if n <= 3 {
        let mut b: Vec<usize> = (0..n).collect();
        b.rotate_right(1);
        return b;
    }
    let mut k = k;
    let mut ans = vec![0; n];
    ans[0] = n - 1;
    let mut used = vec![false; n];
    used[n - 1] = true;
    let mut u = union_find::UF::new(n);
    u.unite(0, n - 1);
    for i in 1..(n - 1) {
        let mut j = 0;
        while k >= a[n - i] {
            if j != i && !used[j] && !u.same(j, i) {
                k -= a[n - i];
            }
            j += 1;
        }
        while used[j] || u.same(i, j) {
            j += 1;
        }
        ans[i] = j;
        used[j] = true;
        assert!(u.unite(i, j).is_some());
    }
    ans[n - 1] = used.iter().position(|p| !*p).unwrap();
    ans
}

fn solve(n: usize, k: u64, a: &[u64], b: &[u64]) -> Vec<usize> {
    assert!(k < b[n]);
    if n == 0 {
        return vec![];
    }
    let mut s = 0u64;
    let mut i = 1;
    while s.saturating_add(a[i].saturating_mul(b[n - i])) <= k {
        s += a[i] * b[n - i];
        i += 1;
    }
    let mut l = solve2(i, (k - s) / b[n - i], a);
    let mut r = solve(n - i, (k - s) % b[n - i], a, b);
    add(&mut r, i);
    l.append(&mut r);
    l
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        p: [(usize, u64); t],
    }
    let n = 50;
    let mut a = vec![1u64; n + 1];
    for i in 4..=n {
        a[i] = (i - 2) as u64 * a[i - 1];
    }
    let mut b = vec![0u64; n + 1];
    b[0] = 1;
    for i in 1..=n {
        for j in 1..=i {
            b[i] = b[i].saturating_add(a[j].saturating_mul(b[i - j]));
        }
    }
    for (n, k) in p {
        let k = k - 1;
        if k >= b[n] {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut ans = solve(n, k, &a, &b);
        add(&mut ans, 1);
        for (i, a) in ans.into_iter().enumerate() {
            if i > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", a).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}
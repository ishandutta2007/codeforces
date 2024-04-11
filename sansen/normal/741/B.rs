// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        if *self > x {
            *self = x;
            true
        } else {
            false
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        if *self < x {
            *self = x;
            true
        } else {
            false
        }
    }
}
// ---------- end chmin, chmax ----------
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

fn run() {
    input! {
        n: usize,
        m: usize,
        w: usize,
        a: [usize; n],
        b: [u64; n],
        e: [(usize1, usize1); m],
    }
    let mut p = vec![];
    for (a, b) in a.iter().zip(b.iter()) {
        p.push(vec![(*a, *b)]);
    }
    let mut u = union_find::UF::new(n);
    for (x, y) in e {
        if let Some((x, y)) = u.unite(x, y) {
            let mut q = vec![];
            std::mem::swap(&mut p[y], &mut q);
            p[x].append(&mut q);
        }
    }
    let mut dp = vec![0; w + 1];
    for i in 0..n {
        if i != u.root(i) {
            continue;
        }
        let mut next = dp.clone();
        let mut sum = (0, 0);
        for &(a, b) in p[i].iter() {
            for j in a..=w {
                next[j].chmax(dp[j - a] + b);
            }
            sum.0 += a;
            sum.1 += b;
        }
        for j in sum.0..=w {
            next[j].chmax(dp[j - sum.0] + sum.1);
        }
        dp = next;
    }
    let ans = dp[w];
    println!("{}", ans);
}

fn main() {
    run();
}
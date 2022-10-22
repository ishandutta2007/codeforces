mod union_find {
    pub struct UF {
        p: Vec<i32>,
    }
    #[allow(dead_code)]
    impl UF {
        pub fn new(n: usize) -> UF {
            UF {p: vec![-1; n] }
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
                std::mem::swap(&mut x, &mut y);
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
        a: [u64; n],
        e: [(usize, usize, u64); m],
    }
    let mut k = 0;
    let mut a: Vec<(u64, usize)> = a.into_iter().map(|x| {k += 1; (x, k)}).collect();
    a.sort();
    let mut e: Vec<(u64, usize, usize)> = e.into_iter().map(|(a, b, w)| (w, a, b)).collect();
    let (c, x) = a[0];
    for &(w, v) in a[1..].iter() {
        e.push((c + w, x, v));
    }
    e.sort();
    let mut u = union_find::UF::new(n + 1);
    let mut cost = 0;
    for (c, a, b) in e {
        if !u.same(a, b) {
            u.unite(a, b);
            cost += c;
        }
    }
    println!("{}", cost);
}

fn main() {
    run();
}
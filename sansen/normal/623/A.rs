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

fn run() {
    input! {
        n: usize,
        m: usize,
        e: [(usize1, usize1); m],
    }
    let mut e = e;
    for e in e.iter_mut() {
        if e.1 < e.0 {
            *e = (e.1, e.0);
        }
    }
    e.sort();
    let mut deg = vec![0; n];
    for &(a, b) in e.iter() {
        deg[a] += 1;
        deg[b] += 1;
    }
    let mut ans = vec![n; n];
    for i in 0..n {
        if deg[i] == n - 1 {
            ans[i] = 1;
        }
    }
    let mut u = union_find::UF::new(n);
    for &(a, b) in e.iter() {
        if deg[a] != n - 1 && deg[b] != n - 1 {
            u.unite(a, b);
        }
    }
    let mut id = 0;
    let mut add = 2;
    for i in 0..n {
        if deg[i] != n - 1 && i == u.root(i) {
            ans[i] = id;
            id += add;
            add = 1;
        }
    }
    if id > 3 {
        println!("No");
        return;
    }
    for i in 0..n {
        for j in (i + 1)..n {
            let x = u.root(i);
            let y = u.root(j);
            if ans[x] == ans[y] || ans[x] == ans[y] + 1 || ans[x] + 1 == ans[y] {
                if e.binary_search(&(i, j)).is_err() {
                    println!("No");
                    return;
                }
            }
        }
    }
    println!("Yes");
    let mut s = String::new();
    let op: Vec<char> = "abc".chars().collect();
    for i in 0..n {
        s.push(op[ans[u.root(i)]]);
    }
    println!("{}", s);
}

fn main() {
    run();
}
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
        h: usize,
        w: usize,
        s: [chars; h],
    }
    let mut u = union_find::UF::new(h * w);
    for i in 0..h {
        for j in 0..w {
            if s[i][j] != '.' {
                continue;
            }
            for &(x, y) in [(i + 1, j), (i, j + 1)].iter() {
                if x < h && y < w && s[x][y] == '.' {
                    u.unite(i * w + j, x * w + y);
                }
            }
        }
    }
    let mut ans = String::new();
    for x in 0..h {
        for y in 0..w {
            if s[x][y] == '.' {
                ans.push('.');
                continue;
            }
            let mut p = vec![];
            for &(x, y) in [(x - 1, y), (x + 1, y), (x, y - 1), (x, y + 1)].iter() {
                if x < h && y < w && s[x][y] == '.' {
                    p.push(u.root(x * w + y));
                }
            }
            p.sort();
            p.dedup();
            let mut size = 1;
            for p in p {
                size += u.get_size(p);
            }
            size %= 10;
            ans.push(size.to_string().chars().next().unwrap());
        }
        ans.push('\n');
    }
    print!("{}", ans);
}

fn main() {
    run();
}
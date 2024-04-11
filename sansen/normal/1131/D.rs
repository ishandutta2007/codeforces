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

fn no() {
    println!("No");
    std::process::exit(0);
}

fn dfs(v: usize, g: &Vec<Vec<usize>>, dp: &mut [u32], state: &mut [u32]) {
    assert!(state[v] == 0);
    state[v] = 1;
    for &u in &g[v] {
        if state[u] == 1 {
            no();
        }
        if state[u] == 0 {
            dfs(u, g, dp, state);
        }
        dp[v] = std::cmp::max(dp[v], dp[u] + 1);
    }
    state[v] = 2;
}

fn run() {
    input! {
        n: usize,
        m: usize,
        s: [chars; n],
    }
    let mut u = union_find::UF::new(n + m);
    for i in 0..n {
        for j in 0..m {
            if s[i][j] == '=' {
                u.unite(i, j + n);
            }
        }
    }
    let mut g = vec![vec![]; n + m];
    for i in 0..n {
        for j in 0..m {
            if s[i][j] == '=' {
                continue;
            }
            let a = u.root(i);
            let b = u.root(j + n);
            if a == b {
                no();
            }
            if s[i][j] == '>' {
                g[a].push(b);
            } else {
                g[b].push(a);
            }
        }
    }
    let mut dp = vec![1; n + m];
    let mut state = vec![0; n + m];
    for i in 0..(n + m) {
        if state[i] > 0 {
            continue;
        }
        dfs(i, &g, &mut dp, &mut state);
    }
    let mut ans = String::new();
    ans.push_str("Yes\n");
    for i in 0..n {
        ans.push_str(&format!("{} ", dp[u.root(i)]));
    }
    ans.pop();
    ans.push('\n');
    for j in n..(n + m) {
        ans.push_str(&format!("{} ", dp[u.root(j)]));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
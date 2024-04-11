use std::io::Write;

// 
// 
// 
// 
//
// 
// 
// 
// 
//
// 
// 
// 2
// 
//
// 
// 
//
// OK

fn dfs(v: usize, g: &mut [Vec<usize>], ans: &mut Vec<(usize, usize)>) {
    while let Some(u) = g[v].pop() {
        dfs(u, g, ans);
        ans.push((u, v));
    }
}

fn run() {
    input! {
        n: usize,
        e: [(usize, usize); n],
    }
    let mut g = vec![vec![]; 2 * n + 1];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    let mut board = vec![vec![]; 2];
    let mut map1 = vec![vec![]; 2];
    let mut map2 = vec![vec![]; 2];
    for i in 1..=(2 * n) {
        if g[i].len() > 0 {
            let mut ans = vec![];
            dfs(i, &mut g, &mut ans);
            if ans.len() == 2 {
                println!("-1");
                return;
            }
            let n = ans.len() / 2;
            let mut a = vec![vec![0; n]; 2];
            for (i, p) in ans.iter().enumerate() {
                if i < n {
                    a[0][i] = p.0;
                } else {
                    a[1][2 * n - 1 - i] = p.0;
                }
            }
            board[0].extend_from_slice(&a[0]);
            board[1].extend_from_slice(&a[1]);
            let mut s = vec![vec!['.'; n]; 2];
            s[0] = "LR".chars().cycle().take(n).collect::<Vec<_>>();
            s[1] = "LR".chars().cycle().take(n).collect::<Vec<_>>();
            if n % 2 == 1 {
                s[0][n - 1] = 'U';
                s[1][n - 1] = 'D';
            }
            for (map, s) in map1.iter_mut().zip(s.iter()) {
                map.extend_from_slice(s);
            }
            s[0].rotate_right(1);
            s[1].rotate_right(1);
            if n % 2 == 0 {
                s[0][n - 1] = 'U';
                s[1][n - 1] = 'D';
                s[0][0] = 'U';
                s[1][0] = 'D';
            }
            for (map, s) in map2.iter_mut().zip(s.iter()) {
                map.extend_from_slice(s);
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{} {}", 2, n).ok();
    use util::*;
    for b in board {
        writeln!(out, "{}", b.iter().join(" ")).ok();
    }
    for b in map1 {
        writeln!(out, "{}", b.iter().join("")).ok();
    }
    for b in map2 {
        writeln!(out, "{}", b.iter().join("")).ok();
    }
}

fn main() {
    run();
}

// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
// ---------- end input macro ----------
mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
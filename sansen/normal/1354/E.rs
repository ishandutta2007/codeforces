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

fn impossible() {
    println!("NO");
    std::process::exit(0);
}

fn run() {
    input! {
        n: usize,
        m: usize,
        count: [usize; 3],
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    let mut depth = vec![n; n];
    let mut a = vec![];
    let mut used = vec![false; n];
    for i in 0..n {
        if used[i] {
            continue;
        }
        used[i] = true;
        let mut vertex = vec![vec![]; 2];
        depth[i] = 0;
        let mut dfs = vec![i];
        while let Some(v) = dfs.pop() {
            let d = depth[v];
            vertex[d & 1].push(v);
            for &u in g[v].iter() {
                if !used[u] {
                    used[u] = true;
                    depth[u] = d + 1;
                    dfs.push(u);
                } else {
                    if d & 1 == depth[u] & 1 {
                        impossible();
                    }
                }
            }
        }
        a.push(vertex);
    }
    let mut dp = vec![vec![false; n + 1]; a.len() + 1];
    dp[0][0] = true;
    for (i, a) in a.iter().enumerate() {
        let x = a[0].len();
        let y = a[1].len();
        for j in 0..=(n - x - y) {
            let b = dp[i][j];
            dp[i + 1][j + x] |= b;
            dp[i + 1][j + y] |= b;
        }
    }
    if !dp[a.len()][count[1]] {
        impossible();
    }
    let mut assign = vec![0i32; n];
    let mut pos = count[1];
    for (i, a) in a.iter().enumerate().rev() {
        let x = a[0].len();
        let y = a[1].len();
        if pos >= x && dp[i][pos - x] {
            for a in a[0].iter() {
                assign[*a] = 1;
            }
            pos -= x;
        } else {
            for a in a[1].iter() {
                assign[*a] = 1;
            }
            pos -= y;
        }
        assert!(dp[i][pos]);
    }
    let mut m = count[2];
    for a in assign.iter_mut() {
        if *a == 0 && m > 0 {
            *a = 2;
            m -= 1;
        }
    }
    assert!(m == 0);
    for &(a, b) in e.iter() {
        assert!((assign[a] - assign[b]).abs() == 1);
    }
    let mut ans = String::from("YES\n");
    for a in assign {
        ans.push_str(&format!("{}", a + 1));
    }
    println!("{}", ans);
}

fn main() {
    run();
}
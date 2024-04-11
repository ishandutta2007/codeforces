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
        w: [usize; n],
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (i, (a, b)) in e.into_iter().enumerate() {
        g[a].push((b, i));
        g[b].push((a, i));
    }
    let mut used = vec![false; n];
    let mut sub = vec![0; n];
    let mut ans = vec![std::usize::MAX; m];
    let mut q = std::collections::VecDeque::new();
    for i in 0..n {
        if g[i].len() <= w[i] {
            used[i] = true;
            q.push_back(i);
        }
    }
    let mut id = m - 1;
    while let Some(v) = q.pop_front() {
        for &(u, k) in g[v].iter() {
            if ans[k] == std::usize::MAX {
                ans[k] = id;
                id -= 1;
            }
            sub[u] += 1;
            if !used[u] && g[u].len() <= w[u] + sub[u] {
                used[u] = true;
                q.push_back(u);
            }
        }
    }
    if ans.iter().any(|a| *a == std::usize::MAX) {
        println!("DEAD");
    } else {
        let mut s = String::new();
        s.push_str(&format!("ALIVE\n"));
        let mut p = vec![0; m];
        for (i, ans) in ans.iter().enumerate() {
            p[*ans] = i + 1;
        }
        for p in p {
            s.push_str(&format!("{} ", p));
        }
        s.pop();
        println!("{}", s);
    }
}

fn main() {
    run();
}
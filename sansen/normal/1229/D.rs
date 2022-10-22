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

fn enumerate(k: usize, n: usize, b: &mut Vec<usize>) -> Vec<Vec<usize>> {
    if k == n - 1 {
        return vec![b.clone()];
    }
    let mut ans = vec![];
    for i in k..n {
        b.swap(k, i);
        ans.append(&mut enumerate(k + 1, n, b));
    }
    b[k..].rotate_left(1);
    ans
}

fn next(a: &[usize], b: &[usize]) -> Vec<usize> {
    let mut c = vec![0; a.len()];
    for i in 0..a.len() {
        c[i] = b[a[i]];
    }
    c
}

fn run() {
    input! {
        n: usize,
        k: usize,
        p: [[usize1; k]; n],
    }
    // 
    let perm = enumerate(0, k, &mut (0..k).collect());
    let size = perm.len();
    // 
    let mut graph = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            graph[i][j] = perm.binary_search(&next(&perm[i], &perm[j])).unwrap();
        }
    }
    // 
    let mut state = vec![];
    let mut set = std::collections::BTreeSet::new();
    for i in 0..size {
        let mut a = vec![0];
        let mut now = i;
        while now != 0 {
            a.push(now);
            now = graph[now][i];
        }
        a.sort();
        state.push(a.clone());
        set.insert(a);
    }
    // 
    let merge = |a: &[usize], b: &[usize]| -> Vec<usize> {
        let mut used = vec![false; size];
        let mut stack = vec![];
        stack.extend_from_slice(a);
        stack.extend_from_slice(b);
        stack.sort();
        stack.dedup();
        for s in stack.iter() {
            used[*s] = true;
        }
        let mut ans = vec![];
        while let Some(v) = stack.pop() {
            ans.push(v);
            for &u in ans.iter() {
                for &k in [graph[v][u], graph[u][v]].iter() {
                    if !used[k] {
                        used[k] = true;
                        stack.push(k);
                    }
                }
            }
        }
        ans.sort();
        ans
    };
    // 
    let mut used: Vec<Vec<usize>> = vec![];
    let mut stack: Vec<Vec<usize>> = set.iter().cloned().collect();
    while let Some(a) = stack.pop() {
        for b in used.iter() {
            let c = merge(&a, b);
            if set.insert(c.clone()) {
                stack.push(c);
            }
        }
        used.push(a);
    }
    used.sort();
    // 
    let size = used.len();
    let p: Vec<usize> = p.into_iter().map(|p| {
        let x = perm.binary_search(&p).unwrap();
        let s = state[x].clone();
        used.binary_search(&s).unwrap()
    }).collect();
    let mut graph = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            let k = merge(&used[i], &used[j]);
            let x = used.binary_search(&k).unwrap();
            graph[i][j] = x;
            graph[j][i] = x;
        }
    }
    // 
    let mut dp = vec![0u64; size];
    let mut ans = 0u64;
    for p in p.into_iter() {
        let mut next = vec![0u64; size];
        for i in 0..size {
            next[graph[i][p]] += dp[i];
        }
        next[p] += 1;
        dp = next;
        for i in 0..size {
            ans += dp[i] * used[i].len() as u64;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
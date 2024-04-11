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
        e: [(usize1, usize1); m],
    }
    let mut g = vec![vec![]; n];
    for (a, b) in e {
        g[a].push(b);
        g[b].push(a);
    }
    //{0, 1, 2}
    let mut ans = 1u64 << n as u64;
    //{0, 2}
    let mut connected = 0;
    let mut used = vec![false; n];
    for v in 0..n {
        if used[v] {
            continue;
        }
        connected += 1;
        used[v] = true;
        let mut s = vec![];
        s.push(v);
        while let Some(v) = s.pop() {
            for &u in &g[v] {
                if !used[u] {
                    used[u] = true;
                    s.push(u);
                }
            }
        }
    }
    ans -= 1 << connected;
    //{0}, {2}
    let mut isolated = 0;
    for v in 0..n {
        if g[v].len() == 0 {
            isolated += 1;
        }
    }
    ans += 2 << isolated;
    //{1}
    let mut way = 1;
    let mut used = vec![false; n];
    for v in 0..n {
        if used[v] {
            continue;
        }
        let mut d = vec![41; n];
        d[v] = 0;
        let mut q = std::collections::VecDeque::new();
        q.push_back(v);
        let mut a = vec![];
        while let Some(v) = q.pop_front() {
            used[v] = true;
            a.push(v);
            for &u in &g[v] {
                if d[u] > d[v] + 1 {
                    d[u] = d[v] + 1;
                    q.push_back(u);
                }
            }
        }
        for v in a {
            for &u in &g[v] {
                if (d[u] ^ d[v]) & 1 == 0 {
                    way = 0;
                }
            }
        }
        way *= 2;
    }
    ans += way;
    //{}
    if m == 0 {
        ans -= 1 << n as u64;
    }
    //{0, 1}, {1, 2}
    let m = n / 2;
    let mut dp = vec![0; 1 << m];
    for i in 0..(1 << m) {
        let mut ok = 1;
        for j in 0..m {
            if (i >> j) & 1 == 0 {
                continue;
            }
            for &u in &g[j] {
                if u < m && (i >> u) & 1 == 1 {
                    ok = 0;
                }
            }
        }
        dp[i] = ok;
    }
    for j in 0..m {
        for i in 0..(1 << m) {
            if (i >> j) & 1 == 1 {
                dp[i] += dp[i ^ (1 << j)];
            }
        }
    }
    for i in 0..(1 << (n - m)) {
        let mut ok = true;
        for j in 0..(n - m) {
            if (i >> j) & 1 == 0 {
                continue;
            }
            let v = j + m;
            for &u in &g[v] {
                if u >= m && (i >> (u - m)) & 1 == 1 {
                    ok = false;
                }
            }
        }
        if !ok {
            continue;
        }
        let mut bit = (1 << m) - 1;
        for j in 0..(n - m) {
            if (i >> j) & 1 == 0 {
                continue;
            }
            let v = j + m;
            for &u in &g[v] {
                if u < m {
                    bit &= !(1 << u);
                }
            }
        }
        ans -= 2 * dp[bit];
    }
    println!("{}", ans);
}

fn main() {
    run();
}
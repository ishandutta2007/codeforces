use std::io::Write;

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
}

fn solve() {
    let n = read()[0];
    let mut g = vec![vec![]; n];
    for _ in 1..n {
        let a = read();
        let x = a[0] - 1;
        let y = a[1] - 1;
        g[x].push(y);
        g[y].push(x);
    }
    let mut query_cnt = 0;
    let mut query = |v: &[usize]| -> (usize, u32) {
        assert!(query_cnt < 14);
        assert!(v.len() > 0);
        query_cnt += 1;
        let mut s = String::new();
        s.push_str(&format!("? {}", v.len()));
        for v in v.iter() {
            s.push_str(&format!(" {}", *v + 1));
        }
        println!("{}", s);
        std::io::stdout().flush().ok();
        let a = read();
        (a[0] - 1, a[1] as u32)
    };
    let ask = (0..n).collect::<Vec<_>>();
    let (mid, dis) = query(&ask);
    let mut dp = vec![0; n];
    let mut stack = vec![(mid, mid)];
    while let Some((v, p)) = stack.pop() {
        for &u in g[v].iter() {
            if u != p {
                dp[u] = dp[v] + 1;
                stack.push((u, v));
            }
        }
    }
    let mut ok = (0, mid);
    let mut ng = *dp.iter().max().unwrap() + 1;
    while ng - ok.0 > 1 {
        let m = (ok.0 + ng) / 2;
        let mut a = vec![];
        for (v, d) in dp.iter().enumerate() {
            if *d == m {
                a.push(v);
            }
        }
        let (x, w) = query(&a);
        if w == dis {
            ok = (m, x);
        } else {
            ng = m;
        }
    }
    let mut dp = vec![0; n];
    let mut stack = vec![(ok.1, ok.1)];
    while let Some((v, p)) = stack.pop() {
        for &u in g[v].iter() {
            if u != p {
                dp[u] = dp[v] + 1;
                stack.push((u, v));
            }
        }
    }
    let mut a = vec![];
    for (v, d) in dp.iter().enumerate() {
        if *d == dis {
            a.push(v);
        }
    }
    let (x, _) = query(&a);
    println!("! {} {}", x + 1, ok.1 + 1);
    std::io::stdout().flush().ok();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    assert!(s.trim().eq("Correct"));
}

fn run() {
    let t = read()[0];
    for _ in 0..t {
        solve();
    }
}

fn main() {
    run();
}
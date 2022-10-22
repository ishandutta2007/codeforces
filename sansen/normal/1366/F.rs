fn read() -> (usize, Vec<(usize, usize, i64)>, i64) {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).ok();
    let mut it = s.trim().split_whitespace();
    let mut next = || it.next().unwrap();
    let n = next().parse::<usize>().unwrap();
    let m = next().parse::<usize>().unwrap();
    let q = next().parse::<i64>().unwrap();
    let e = (0..m)
        .map(|_| {
            let a = next().parse::<usize>().unwrap() - 1;
            let b = next().parse::<usize>().unwrap() - 1;
            let c = next().parse::<i64>().unwrap();
            (a, b, c)
        })
        .collect();
    (n, e, q)
}

fn main() {
    let (n, e, q) = read();
    let mut g = vec![vec![]; n];
    for &(a, b, c) in e.iter() {
        g[a].push((b, c));
        g[b].push((a, c));
    }
    const MOD: i64 = 1_000_000_007;
    let inf = 10i64.pow(18);
    let mut dp = vec![-inf; n];
    dp[0] = 0;
    let pre = q.min(n as i64);
    let mut ans = 0;
    for _ in 0..pre {
        let mut next = vec![-inf; n];
        for (v, &d) in dp.iter().enumerate() {
            for &(u, c) in g[v].iter() {
                next[u] = next[u].max(c + d);
            }
        }
        dp = next;
        ans += *dp.iter().max().unwrap();
    }
    if q > pre {
        let mut line = vec![];
        for (v, &d) in dp.iter().enumerate() {
            if d < 0 {
                continue;
            }
            for &(_, c) in g[v].iter() {
                line.push((c, d - c * pre));
            }
        }
        line.sort();
        line.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 = a.1;
                true
            }
        });
        let mut deq = std::collections::VecDeque::<(i64, i64)>::new();
        for (a, b) in line {
            while deq.len() > 1 {
                let len = deq.len();
                let (c, d) = deq[len - 1];
                let (e, f) = deq[len - 2];
                if (d - b) * (a - e) <= (f - b) * (a - c) {
                    deq.pop_back();
                } else {
                    break;
                }
            }
            deq.push_back((a, b));
        }
        let mut pre = pre;
        while pre < q {
            while deq.len() > 1 {
                let (a, b) = deq[0];
                let (c, d) = deq[1];
                if a * (pre + 1) + b <= c * (pre + 1) + d {
                    deq.pop_front();
                } else {
                    break;
                }
            }
            let (a, b) = deq[0];
            let func = |x: i64| -> i64 { (x * (x + 1) / 2 % MOD * a + b * x) % MOD };
            if deq.len() > 1 {
                let (c, d) = deq[1];
                let x = q.min((d - b) / (a - c));
                ans += func(x) - func(pre) + MOD;
                pre = x;
            } else {
                ans += func(q) - func(pre) + MOD;
                pre = q;
            }
        }
    }
    ans %= MOD;
    println!("{}", ans);
}
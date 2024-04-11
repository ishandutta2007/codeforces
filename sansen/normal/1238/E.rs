use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let _len: usize = it.next().unwrap().parse().unwrap();
    let n: usize = it.next().unwrap().parse().unwrap();
    let s: Vec<usize> = it.next().unwrap().chars().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    let mut cnt = vec![vec![0u64; n]; n];
    for s in s.windows(2) {
        let a = s[0];
        let b = s[1];
        cnt[a][b] += 1;
    }
    let mut cost = vec![0; 1 << n];
    for i in 1..n {
        for j in 0..i {
            let s = cnt[i][j] + cnt[j][i];
            cost[1 << i] += s;
            cost[1 << j] += s;
            cost[(1 << i) | (1 << j)] -= 2 * s;
        }
    }
    for i in 0..n {
        for j in 0..(1 << n) {
            if j >> i & 1 == 1 {
                cost[j] += cost[j ^ (1 << i)];
            }
        }
    }
    let mut dp = vec![std::u64::MAX; 1 << n];
    dp[0] = 0;
    for i in 0..(1 << n) {
        dp[i] += cost[i];
        let v = dp[i];
        for j in 0..n {
            if i >> j & 1 == 0 {
                let k = i | (1 << j);
                dp[k] = std::cmp::min(dp[k], v);
            }
        }
    }
    let ans = dp[(1 << n) - 1];
    println!("{}", ans);
}

fn main() {
    run();
}
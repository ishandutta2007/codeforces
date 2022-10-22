use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let s: Vec<char> = it.next().unwrap().chars().collect();
    let mut dp = vec![vec![0; n]; n];
    for len in 1..=n {
        for l in 0..=(n - len) {
            let r = l + len - 1;
            dp[l][r] = len;
            if l + 1 < n {
                dp[l][r] = dp[l + 1][r] + 1;
            }
            for k in (l + 1)..=r {
                if s[l] == s[k] {
                    dp[l][r] = std::cmp::min(dp[l][r], dp[l + 1][k - 1] + dp[k][r]);
                }
            }
        }
    }
    println!("{}", dp[0][n - 1]);
}

fn main() {
    run();
}
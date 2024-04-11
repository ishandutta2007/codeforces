fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let mut n: u64 = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();
    let p = 10;
    let mut cnt = vec![0; p];
    while n > 0 {
        let k = (n % p as u64) as usize;
        cnt[k] += 1;
        n /= p as u64;
    }
    let mut step = vec![1; p + 1];
    for i in (0..p).rev() {
        step[i] = step[i + 1] * (cnt[i] + 1);
    }
    let len = step[0];
    let mut dp = vec![vec![0u64; len]; m];
    dp[0][len - 1] = 1;
    let mut q = std::collections::VecDeque::new();
    q.push_back((0, len - 1));
    while let Some((rem, v)) = q.pop_front() {
        for d in 0..p {
            let a = v % step[d] / step[d + 1];
            if a > 0 && !(d == 0 && v == len - 1) {
                let u = v - step[d + 1];
                let r = (10 * rem + d) % m;
                if dp[r][u] == 0 {
                    q.push_back((r, u));
                }
                dp[r][u] += dp[rem][v];
            }
        }
    }
    let ans = dp[0][0];
    println!("{}", ans);
}

fn main() {
    run();
}
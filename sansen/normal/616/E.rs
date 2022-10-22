fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: u64 = it.next().unwrap().parse().unwrap();
    let m: u64 = it.next().unwrap().parse().unwrap();
    const MOD: u64 = 1_000_000_007;
    let mut sum = 0;
    let mut k = 1;
    while k * k <= n && k <= m {
        sum = (sum + n / k * k) % MOD;
        k += 1;
    }
    let mut q = n / k;
    while q > 0 {
        let l = n / (q + 1);
        let r = std::cmp::min(m, n / q);
        if l < r {
            let l = l % MOD;
            let r = r % MOD;
            let v = (MOD * MOD + r * (r + 1) - l * (l + 1)) % MOD * (MOD + 1) / 2 % MOD;
            sum = (sum + v * q) % MOD;
            q -= 1;
        } else {
            break;
        }
    }
    let mut ans = (n % MOD * (std::cmp::min(n, m) % MOD) % MOD - sum + MOD) % MOD;
    if m > n {
        ans = (ans + n % MOD * ((m - n) % MOD)) % MOD;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
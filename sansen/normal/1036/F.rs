use std::io::Read;
use std::io::Write;

fn sign(mut k: usize) -> i64 {
    let mut b = 2;
    let mut ans = 1;
    while b * b <= k {
        if k % b == 0 {
            ans *= -1;
            k /= b;
            while k % b == 0 {
                ans = 0;
                k /= b;
            }
        }
        b += 1;
    }
    if k > 1 {
        ans *= -1;
    }
    ans
}

fn pow(r: i64, mut n: usize) -> i64 {
    let mut ans = 1i64;
    let mut s = r;
    while n > 0 {
        if n & 1 == 1 {
            ans = ans.saturating_mul(s);
        }
        s = s.saturating_mul(s);
        n >>= 1;
    }
    ans
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a: Vec<(i64, usize)> = (0..n).map(|k| (it.next().unwrap().parse().unwrap(), k)).collect();
    a.sort();
    a.reverse();
    let mut s = vec![0; 61];
    for k in 2..=60 {
        s[k] = sign(k);
    }
    let mut imos = vec![0; n + 1];
    for k in 3..=60 {
        if (1 << k as i64) > a[0].0 || s[k] == 0 {
            continue;
        }
        let mut r = 2;
        while pow(r + 1, k) <= a[0].0 {
            r += 1;
        }
        let mut i = 0;
        while i < n {
            while r > 1 && pow(r, k) > a[i].0 {
                r -= 1;
            }
            let mut j = i + 1;
            while j < n && pow(r, k) <= a[j].0 {
                j += 1;
            }
            imos[i] += s[k] * (r - 1);
            imos[j] -= s[k] * (r - 1);
            i = j;
        }
    }
    for i in 1..n {
        imos[i] += imos[i - 1];
    }
    let mut ans = vec![0; n];
    for (i, a) in a.iter().enumerate() {
        ans[a.1] = a.0 - 1 + imos[i];
    }
    a.sort_by_key(|a| a.1);
    for i in 0..n {
        let a: i64 = a[i].0;
        let mut ans = ans[i];
        let mut l = 1;
        let mut r = 1_000_000_000 + 1;
        while r - l > 1 {
            let m = (l + r) / 2;
            if pow(m, 2) <= a {
                l = m;
            } else {
                r = m;
            }
        }
        ans -= l - 1;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
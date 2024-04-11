use std::io::Read;

fn z_algorithm<T: Eq>(s: &[T]) -> Vec<usize> {
    let len = s.len();
    let mut a = vec![0; len];
    a[0] = len;
    let mut i = 1;
    let mut j = 0;
    while i < len {
        while i + j < len && s[j] == s[i + j] {
            j += 1;
        }
        a[i] = j;
        if j == 0 {
            i += 1;
            continue;
        }
        let mut k = 1;
        while i + k < len && k + a[k] < j {
            a[i + k] = a[k];
            k += 1;
        }
        i += k;
        j -= k;
    }
    a
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let a: u32 = it.next().unwrap().parse().unwrap();
    let b: u32 = it.next().unwrap().parse().unwrap();
    let mut s: Vec<char> = it.next().unwrap().chars().collect();
    s.reverse();
    s.push('\0');
    s.reverse();
    let s = s;
    let mut dp = vec![std::u32::MAX; n + 1];
    dp[0] = 0;
    for i in 0..n {
        let v = dp[i];
        dp[i + 1] = std::cmp::min(dp[i + 1], v + a);
        let mut x = vec![];
        x.extend_from_slice(&s[(i + 1)..]);
        let len = x.len();
        x.extend_from_slice(&s[..(i + 1)]);
        let z = z_algorithm(&x);
        let mut r = 0;
        for &z in z[len..].iter() {
            r = std::cmp::max(r, z);
        }
        for j in (i + 1)..std::cmp::min(n + 1, i + 1 + r) {
            dp[j] = std::cmp::min(dp[j], v + b);
        }
    }
    println!("{}", dp[n]);
}

fn main() {
    run();
}
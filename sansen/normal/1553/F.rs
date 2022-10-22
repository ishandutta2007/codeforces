pub fn quot_range<F>(n: u32, mut f: F)
where
    F: FnMut(u32, u32, u32)
{
    let mut pre = (0, 0);
    for d in 1.. {
        let q = n / d;
        if pre != (0, 0) {
            let (q, l, r) = (pre.0, q + 1, pre.1);
            f(l, r, q);
        }
        if q < d {
            break;
        }
        pre = (d, q);
        f(d, d, q);
        if q == d {
            break;
        }
    }
}

fn read() -> Vec<usize> {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    it.flat_map(|s| s.parse()).collect()
}

fn main() {
    use std::fmt::Write;
    let mut out = String::new();
    let a = read();
    let m = *a.iter().max().unwrap();
    let batch = 1000;
    let mut ans = 0;
    for (i, b) in a.chunks(batch).enumerate() {
        let mut cnt = vec![0; m + 2];
        let mut sum = vec![0; m + 2];
        for a in a.iter().take(batch * i) {
            cnt[*a] += 1;
            sum[*a] += *a;
        }
        for i in (1..m).rev() {
            cnt[i] += cnt[i + 1];
            sum[i] += sum[i + 1];
        }
        for (j, &x) in b.iter().enumerate() {
            for &b in b[..j].iter() {
                ans += x % b + b % x;
            }
            ans += sum[1];
            for j in 1..=(m / x) {
                ans -= x * cnt[j * x];
            }
            ans += i * batch * x;
            quot_range(x as u32, |l, r, q| {
                ans -= q as usize * (sum[l as usize] - sum[r as usize + 1]);
            });
            write!(&mut out, "{} ", ans).ok();
        }
    }
    out.pop();
    println!("{}", out);
}
// ---------- begin Suffix Array ----------
fn suffix_array<T: Ord + Copy>(s: &[T]) -> Vec<usize> {
    let n = s.len();
    let mut z = Vec::with_capacity(n);
    z.extend_from_slice(s);
    z.sort();
    z.dedup();
    let mut sa: Vec<usize> = (0..n).collect();
    sa.sort_by(|&a, &b| s[a].cmp(&s[b]).then(b.cmp(&a)));
    let mut c = Vec::with_capacity(n);
    for s in s.iter() {
        c.push(z.binary_search(s).unwrap());
    }
    let mut classes = vec![0; n];
    let mut cnt = vec![0; n];
    let mut len = 1;
    let mut id = 0;
    while id < n && len < n {
        id = 1;
        let mut prev = sa[0];
        classes[prev] = id - 1;
        cnt[0] = 0;
        for (i, &sa) in sa.iter().enumerate().skip(1) {
            if c[sa] == c[prev] && prev < n - len && c[prev + len / 2] == c[sa + len / 2] {
                classes[sa] = classes[prev];
            } else {
                id += 1;
                classes[sa] = id - 1;
                cnt[id - 1] = i;
            }
            prev = sa;
        }
        c.clone_from(&sa);
        for c in c.iter() {
            if *c >= len {
                let k = *c - len;
                sa[cnt[classes[k]]] = k;
                cnt[classes[k]] += 1;
            }
        }
        std::mem::swap(&mut classes, &mut c);
        len <<= 1;
    }
    sa
}
// ---------- end Suffix Array ----------
// ---------- begin z-algorithm ----------
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
// ---------- end z-algorithm ----------

use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let m: usize = it.next().unwrap().parse().unwrap();
    let k: u64 = it.next().unwrap().parse().unwrap();
    let s: Vec<char> = it.next().unwrap().chars().collect();
    let sa = suffix_array(&s);
    let mut a = vec![];
    for i in (sa[0] + 1)..=n {
        a.push(&s[sa[0]..i]);
    }
    for i in 1..n {
        let mut lcp = 0;
        for (a, b) in s[sa[i - 1]..].iter().zip(s[sa[i]..].iter()) {
            if *a != *b {
                break;
            }
            lcp += 1;
        }
        for j in (sa[i] + lcp + 1)..=n {
            a.push(&s[sa[i]..j]);
        }
    }
    let mut ok = 0;
    let mut ng = a.len();
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let val = a[mid];
        let mut z = vec![];
        z.extend_from_slice(val);
        z.push('$');
        z.extend_from_slice(&s);
        let x = z_algorithm(&z);
        let x = &x[(val.len() + 1)..];
        let mut dp = vec![0u64; n + 1];
        dp[0] = 1;
        for _ in 0..m {
            let mut imos = vec![0u64; n + 1];
            for (i, (&x, &v)) in x.iter().zip(dp.iter()).enumerate() {
                if x >= val.len() {
                    let y = i + val.len();
                    imos[y] = imos[y].saturating_add(v);
                } else if i + x < n && s[i + x] > val[x] {
                    let y = i + x + 1;
                    imos[y] = imos[y].saturating_add(v);
                }
            }
            for i in 1..=n {
                imos[i] = imos[i].saturating_add(imos[i - 1]);
            }
            dp = imos;
        }
        if dp[n] >= k {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let ans: String = a[ok].iter().cloned().collect();
    println!("{}", ans);
}

fn main() {
    run();
}
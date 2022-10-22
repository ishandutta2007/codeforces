fn read() -> Vec<u32> {
    let mut s = String::new();
    use std::io::Read;
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    it.flat_map(|s| s.parse()).collect()
}

fn edge(a: &[u32], b: &[u32], k: u32) -> u64 {
    if a.is_empty() || b.is_empty() {
        return std::u64::MAX;
    }
    if k == 0 {
        return 0;
    }
    let k = k - 1;
    let x = a.iter().position(|a| *a >> k & 1 == 1).unwrap_or(a.len());
    let (p, q) = a.split_at(x);
    let x = b.iter().position(|a| *a >> k & 1 == 1).unwrap_or(b.len());
    let (r, s) = b.split_at(x);
    let mut res = edge(p, r, k).min(edge(q, s, k));
    if res == std::u64::MAX {
        res = edge(p, s, k).min(edge(q, r, k)) + (1 << k);
    }
    res
}

fn calc(a: &[u32], k: u32) -> u64 {
    if a.len() <= 1 || k == 0 {
        return 0;
    }
    let k = k - 1;
    let x = a.iter().position(|a| *a >> k & 1 == 1).unwrap_or(a.len());
    let (l, r) = a.split_at(x);
    let mut res = calc(l, k) + calc(r, k);
    if l.len() > 0 && r.len() > 0 {
        res += edge(l, r, k + 1);
    }
    res
}

fn main() {
    let mut a = read();
    a.sort();
    let ans = calc(&a, 30);
    println!("{}", ans);
}
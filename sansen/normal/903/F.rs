use std::io::Read;

fn calc(bit: usize, cost: u32, k: usize, a: &[u32], mask: &[Vec<usize>], trans: &mut Vec<(usize, u32)>) {
    if k >= a.len() {
        trans.push((bit, cost));
        return;
    }
    calc(bit, cost, k + 1, a, mask, trans);
    for i in 0..(a.len() - k) {
        calc(bit & mask[i][k], cost + a[i], k + 1, a, mask, trans);
    }
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let m = 4;
    let a: Vec<u32> = (0..m).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let s: Vec<Vec<usize>> = it.map(|s| s.chars().map(|c| if c == '*' {1} else {0}).collect()).collect();
    let s: Vec<usize> = (0..n).map(|k| s.iter().map(|s| s[k]).fold(0, |s, a| (s << 1) | a)).collect();
    let mut mask = vec![vec![std::usize::MAX; m]; m];
    for i in 0..m {
        for j in 0..(m - i) {
            for p in 0..=i {
                for q in 0..=i {
                    assert!(q + j < m);
                    mask[i][j] ^= 1 << (m * p + q + j);
                }
            }
        }
    }
    let mut trans = vec![];
    calc(std::usize::MAX, 0, 0, &a, &mask, &mut trans);
    let inf = 1000 * m as u32 * 1000 + 1;
    let mut dp = vec![0; 1 << ((m - 1) * m)];
    for s in s {
        let mut next = vec![inf; 1 << ((m - 1) * m)];
        for (i, v) in dp.into_iter().enumerate() {
            let bit = (i << m) | s;
            for (mask, cost) in trans.iter() {
                let x = mask & bit;
                if let Some(p) = next.get_mut(x) {
                    *p = std::cmp::min(*p, v + cost);
                }
            }
        }
        dp = next;
    }
    let ans = dp[0];
    println!("{}", ans);
}

fn main() {
    run();
}
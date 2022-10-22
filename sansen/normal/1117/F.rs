use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let p: usize = it.next().unwrap().parse().unwrap();
    let s: Vec<usize> = it.next().unwrap().chars().map(|c| c.to_digit(36).unwrap() as usize - 10).collect();
    let a: Vec<Vec<usize>> = (0..p).map(|_| (0..p).map(|_| it.next().unwrap().parse().unwrap()).collect()).collect();
    let mut cnt = vec![0; p];
    for c in s.iter() {
        cnt[*c] += 1;
    }
    let mut last: Vec<usize> = vec![];
    let mut ng = vec![vec![]; 1 << p];
    for &x in s.iter() {
        let mut mask = 1 << x;
        for k in 0..last.len() {
            let y = last[k];
            mask |= 1 << y;
            if a[x][y] == 0 {
                ng[mask].push((1 << x) | (1 << y));
            }
            if y == x {
                last.remove(k);
                break;
            }
        }
        last.insert(0, x);
    }
    let mut valid = vec![true; 1 << p];
    for (i, a) in ng.iter_mut().enumerate() {
        a.sort();
        a.dedup();
        let mut bit = 0;
        while bit < valid.len() {
            for a in a.iter() {
                valid[bit | *a] = false;
            }
            bit = ((bit | i) + 1) & !i;
        }
    }
    let mut ans = n;
    let mut dp = vec![false; 1 << p];
    dp[(1 << p) - 1] = true;
    for i in (0..(1 << p)).rev() {
        if !dp[i] {
            continue;
        }
        let mut len = 0;
        for (j, c) in cnt.iter().enumerate() {
            len += ((i >> j) & 1) * *c;
        }
        ans = std::cmp::min(ans, len);
        for j in 0..p {
            if (i >> j) & 1 == 1 && valid[i ^ (1 << j)] {
                dp[i ^ (1 << j)] = true;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
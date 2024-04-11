fn chmin<T: PartialOrd>(x: &mut T, a: T) {
    if a < *x {
        *x = a;
    }
}

fn run() {
    let mut buf = String::new();
    std::io::stdin().read_line(&mut buf).unwrap();
    let s: Vec<char> = buf.trim().chars().collect();
    buf.clear();
    std::io::stdin().read_line(&mut buf).unwrap();
    let t: Vec<char> = buf.trim().chars().collect();
    let mut g = vec![None; s.len()];
    let mut stack = vec![];
    for (i, &c) in s.iter().enumerate() {
        if c == '.' {
            if let Some(k) = stack.pop() {
                g[k] = Some(i);
            }
        } else {
            stack.push(i);
        }
    }
    let inf = 10000u16;
    //dp[i][j]: s[..i]  t[..j]
    let mut dp = vec![inf; s.len() + 1];
    dp[0] = 0;
    for i in 0..=t.len() {
        let mut next = vec![inf; s.len() + 1];
        for j in 0..s.len() {
            if dp[j] == inf {
                continue;
            }
            let d = dp[j];
            if i < t.len() && s[j] == t[i] {
                chmin(&mut next[j + 1], d);
            }
            if let Some(k) = g[j] {
                chmin(&mut dp[k + 1], d);
            }
            chmin(&mut dp[j + 1], d + 1);
        }
        if i < t.len() {
            dp = next;
        }
    }
    let ans = dp[s.len()];
    println!("{}", ans);
}

fn main() {
    run();
}
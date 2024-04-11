use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<usize> = it.map(|s| s.parse().unwrap()).collect();
    let mut dp = vec![n + 1; n + 1];
    dp[0] = 0;
    for l in 0..n {
        let mut stack = vec![];
        for (i, &v) in a.iter().enumerate().skip(l) {
            let mut val = v;
            while let Some(&u) = stack.last() {
                if u == val {
                    stack.pop();
                    val += 1;
                } else {
                    break;
                }
            }
            stack.push(val);
            if stack.len() == 1 {
                dp[i + 1] = std::cmp::min(dp[i + 1], dp[l] + 1);
            }
        }
    }
    println!("{}", dp[n]);
}

fn main() {
    run();
}
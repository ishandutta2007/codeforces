fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let s: Vec<char> = s.trim().chars().collect();
    let n = s.len();
    let mut ans = 0u64;
    for l in 0..n {
        'outer: for r in (l + 2)..n {
            for k in 1..=((r - l) / 2) {
                if s[r] == s[r - k] && s[r] == s[r - 2 * k] {
                    ans += (n - r) as u64;
                    break 'outer;
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut n: usize = s.trim().parse().unwrap();
    let mut ans = String::new();
    for k in 2..1000 {
        while n % k == 0 {
            ans.push_str(&format!("{}", k));
            n /= k;
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
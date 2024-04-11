fn gcd(a: u64, b: u64) -> u64 {
    if b == 0 {a} else {gcd(b, a % b)}
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let x: u64 = s.trim().parse().unwrap();
    let mut ans = (1, x);
    for k in 2.. {
        if k * k > x {
            break;
        }
        if x % k == 0 && gcd(k, x / k) == 1 {
            ans = (k, x / k);
        }
    }
    println!("{} {}", ans.0, ans.1);
}

fn main() {
    run();
}
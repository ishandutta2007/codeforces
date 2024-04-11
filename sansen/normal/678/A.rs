fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: u64 = it.next().unwrap().parse().unwrap();
    let k: u64 = it.next().unwrap().parse().unwrap();
    let ans = n / k * k + k;
    println!("{}", ans);
}

fn main() {
    run();
}
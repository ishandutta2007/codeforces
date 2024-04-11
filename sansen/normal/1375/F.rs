use std::io::Write;

fn read() -> Vec<i64> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
}

fn run() {
    let mut a = read();
    println!("First");
    std::io::stdout().flush().ok();
    let inf = 3_000_000_000i64;
    println!("{}", inf);
    std::io::stdout().flush().ok();
    let k = read()[0];
    if k <= 0 {
        return;
    }
    a[k as usize - 1] += inf;
    let y = 3 * a[k as usize - 1] - a.iter().sum::<i64>();
    println!("{}", y);
    std::io::stdout().flush().ok();
    let k = read()[0];
    if k <= 0 {
        return;
    }
    a[k as usize - 1] += y;
    let mut b = a.clone();
    b.sort();
    let d = a[1] - a[0];
    assert!(b[2] - b[1] == d);
    println!("{}", d);
    std::io::stdout().flush().ok();
}

fn main() {
    run();
}
use std::io::Write;

fn is_prime(n: u32) -> bool {
    if n <= 1 {
        return false;
    }
    let mut k = 2;
    while k * k <= n {
        if n % k == 0 {
            return false;
        }
        k += 1;
    }
    true
}

fn query(n: u32) -> bool {
    assert!(2 <= n && n <= 100);
    static mut X: usize = 0;
    unsafe {
        assert!(X < 20);
        X += 1;
    }
    println!("{}", n);
    std::io::stdout().flush().ok();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim() == "yes"
}

fn composite() {
    println!("composite");
    std::process::exit(0);
}

fn prime() {
    println!("prime");
    std::process::exit(0);
}

fn run() {
    let sq = [2, 3, 5, 7];
    let mut hit = (0, 0);
    for p in sq.iter() {
        if query(*p) {
            hit.0 = *p;
            hit.1 += 1;
        }
    }
    if hit.1 > 1 {
        composite();
    }
    if hit.1 == 0 {
        prime();
    }
    if query(hit.0.pow(2)) {
        composite();
    }
    for k in 11..=(100 / hit.0) {
        if is_prime(k) && query(hit.0 * k) {
            composite();
        }
    }
    prime();
}

fn main() {
    run();
}
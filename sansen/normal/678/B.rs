fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let y: u32 = s.trim().parse().unwrap();
    let leap = |x: u32| -> bool {
        x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)
    };
    let mut p = 1 + leap(y) as usize;
    let mut q = y + 1;
    while p != 0 || leap(q) != leap(y) {
        p = (p + 1) % 7;
        if leap(q) {
            p = (p + 1) % 7;
        }
        q += 1;
    }
    println!("{}", q);
}

fn main() {
    run();
}
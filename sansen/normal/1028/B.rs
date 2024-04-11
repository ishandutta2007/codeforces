fn run() {
    let a = "5".repeat(1000);
    let mut b = "4".repeat(999);
    b.push('5');
    println!("{}\n{}", a, b);
}

fn main() {
    run();
}
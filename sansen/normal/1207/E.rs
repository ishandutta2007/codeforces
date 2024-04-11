use std::io::Write;

fn run() {
    for i in 0..2 {
        let x = 1 << (7 * i);
        print!("?");
        for j in 1..101 {
            let y = j * x;
            print!(" {}", y);
        }
        println!("");
    }
    std::io::stdout().flush().ok();
    let a: u32 = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let b: u32 = {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        s.trim().parse().unwrap()
    };
    let mask = (1 << 7) - 1;
    let ans = (a & (mask << 7)) + (b & mask);
    println!("! {}", ans);
    std::io::stdout().flush().ok();
}

fn main() {
    run();
}
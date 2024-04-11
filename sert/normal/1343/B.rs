use std::io;

fn read_int() -> i32 {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    return input.trim().parse().unwrap();
}

fn solve() {
    let n = read_int() / 2;
    if n % 2 == 1 {
        println!("NO");
    } else {
        println!("YES");
        for i in 0..n {
            print!("{} ", i * 2 + 2);
        }
        for i in 0..(n + 1) {
            if i != n / 2 {
                print!("{} ", i * 2 + 1);
            }
        }
        println!();
    }
}

fn main() {
    let t: i32 = read_int();
    for _ in 0..t {
        solve();
    }
}
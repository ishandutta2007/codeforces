use std::io::Write;

fn read_line() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s
}

fn query(a: usize, b: usize, c: usize, d: usize, n: usize) -> bool {
    assert!(c >= a && d >= b && c - a + d - b >= n - 1);
    println!("? {} {} {} {}", a, b, c, d);
    std::io::stdout().flush().unwrap();
    let s: Vec<char> = read_line().trim().chars().collect();
    s[0] == 'Y'
}

fn run() {
    let n: usize = read_line().trim().parse().unwrap();
    let mut d = n;
    while d > 1 {
        if query(1, 1, d, n + 1 - d, n) && query(d, n + 1 - d, n, n, n) {
            break;
        }
        d -= 1;
    }
    let mid = (d, n + 1 - d);
    let mut p = (1, 1);
    let mut a = String::new();
    for _ in 1..n {
        if query(p.0 + 1, p.1, n, n, n) {
            p.0 += 1;
            a.push('D');
        } else {
            p.1 += 1;
            a.push('R');
        }
    }
    assert!(p == mid);
    let mut b = vec![];
    let mut p = (n, n);
    for _ in 1..n {
        if query(1, 1, p.0, p.1 - 1, n) {
            p.1 -= 1;
            b.push('R');
        } else {
            p.0 -= 1;
            b.push('D');
        }
    }
    assert!(p == mid);
    while let Some(c) = b.pop() {
        a.push(c);
    }
    println!("! {}", a);
}

fn main() {
    run();
}
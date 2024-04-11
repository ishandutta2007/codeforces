#[allow(unused_imports)]
use std::io::{stdin, stdout, BufWriter, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let t: usize = scan.next();
    for _ in 0..t {
        let n = scan.next();
        let a: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        let b: Vec<i32> = (0..n).map(|_| scan.next()).collect();
        let (one, two): (Vec<_>, Vec<_>) = a.into_iter().zip(b.into_iter()).partition(|(_, i)| *i == 0);
        let sorted = one.iter().zip(one.iter().skip(1)).all(|(a,b)| a <= b) && two.iter().zip(two.iter().skip(1)).all(|(a,b)| a <= b);
        writeln!(out, "{}", if sorted || (!one.is_empty() && !two.is_empty()) { "Yes" } else { "No" }).ok();
    }
}
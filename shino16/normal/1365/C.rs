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
    let n = scan.next();
    let ab : Vec<Vec<usize>> = (0..2).map(|_| (0..n).map(|_| scan.next()).collect()).collect();
    let rev: Vec<Vec<usize>> = (0..2).map(|i| {
        let mut rev = vec![0; n];
        for j in 0..n {
            rev[ab[i][j]-1] = j;
        }
        rev
    }).collect();
    let mut shc = vec![0usize; n];
    for j in 0..n {
        shc[(rev[0][j] + n - rev[1][j]) % n as usize] += 1;
    }
    writeln!(out, "{}", shc.into_iter().fold(0, usize::max)).ok();
}
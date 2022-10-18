#[allow(unused_imports)]
use std::io::{BufWriter, stdin, stdout, Write};

#[derive(Default)]
struct Scanner {
    buffer: Vec<String>
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

fn neigh(r: usize, c: usize, h: usize, w: usize) -> Vec<(usize, usize)> {
    let dr = [1, -1, 0, 0];
    let dc = [0, 0, 1, -1];
    let mut res = Vec::new();
    for (dr, dc) in dr.into_iter().zip(dc.into_iter()) {
        let r1 = r as isize + dr;
        let c1 = c as isize + dc;
        if r1 >= 0 && r1 < h as isize && c1 >= 0 && c1 < h as isize {
            res.push((r1 as usize, c1 as usize));
        }
    }
    res
}

fn main() {
    let mut scan = Scanner::default();
    let out = &mut BufWriter::new(stdout());
    let t: usize = scan.next();
    for _ in 0..t {
        let h = scan.next();
        let w = scan.next();
        let mut a: Vec<Vec<u32>> = (0..h).map(|_| (0..w).map(|_| scan.next()).collect()).collect();
        let cnt = (0..h).filter(|r| (0..w).all(|c| a[*r][c] == 0)).count().min((0..w).filter(|c| (0..h).all(|r| a[r][*c] == 0)).count());
        writeln!(out, "{}", if cnt % 2 == 0 { "Vivek" } else { "Ashish" }).ok();
    }
}
use std::io::Read;
use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    for s in it {
        let n: usize = s.parse().unwrap();
        writeln!(out, "{}", n).ok();
    }
}

fn main() {
    run();
}
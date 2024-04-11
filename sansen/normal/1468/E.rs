use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let mut a: Vec<u32> =  (0..4).flat_map(|_| it.next().unwrap().parse()).collect();
        a.sort();
        let ans = a[0] * a[2];
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
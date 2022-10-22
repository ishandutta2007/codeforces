use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let mut c: Vec<i32> =  (0..3).flat_map(|_| it.next().unwrap().parse()).collect();
        let a: Vec<i32> =  (0..5).flat_map(|_| it.next().unwrap().parse()).collect();
        for (c, a) in c.iter_mut().zip(a.iter()) {
            *c -= *a;
        }
        if c.iter().any(|c| *c < 0) {
            writeln!(out, "NO").ok();
            continue;
        }
        let v = c[0].min(a[3]);
        c[0] -= v;
        c[2] -= a[3] - v;
        if c.iter().any(|c| *c < 0) {
            writeln!(out, "NO").ok();
            continue;
        }
        let v = c[1].min(a[4]);
        c[1] -= v;
        c[2] -= a[4] - v;
        if c.iter().any(|c| *c < 0) {
            writeln!(out, "NO").ok();
            continue;
        }
        writeln!(out, "YES").ok();
    }
}

fn main() {
    run();
}
use std::io::Write;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: u64 = it.next().unwrap().parse().unwrap();
    let k: u64 = it.next().unwrap().parse().unwrap();
    if k * (k - 1) < n {
        println!("NO");
        return;
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "YES").ok();
    let mut pos = (1, 2);
    let mut m = n;
    while m >= 2 {
        m -= 2;
        writeln!(out, "{} {}", pos.0, pos.1).ok();
        writeln!(out, "{} {}", pos.1, pos.0).ok();
        pos.1 += 1;
        if pos.1 > k {
            pos.0 += 1;
            pos.1 = pos.0 + 1;
        }
    }
    if m > 0 {
        writeln!(out, "{} {}", pos.0, pos.1).ok();
    }
}

fn main() {
    run();
}
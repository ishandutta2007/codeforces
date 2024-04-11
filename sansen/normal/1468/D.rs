use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: i32 = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let a: i32 = it.next().unwrap().parse().unwrap();
        let b: i32 = it.next().unwrap().parse().unwrap();
        let mut s: Vec<i32> = (0..m).flat_map(|_| it.next().unwrap().parse()).collect();
        s.sort();
        let free = (b - a).abs() - 1;
        let rem = if a < b {
            a - 1
        } else {
            n - a
        };
        let mut ans = 0;
        for t in 0..free {
            while s.last().map_or(false, |s| *s > free + rem - t) {
                s.pop();
            }
            if s.is_empty() {
                break;
            }
            ans += 1;
            s.pop();
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
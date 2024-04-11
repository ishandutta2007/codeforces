use std::io::*;

fn solve(b: &[usize], n: usize, k: usize) -> bool {
    let m = b.len();
    if (n - m) % (k - 1) != 0 {
        return false;
    }
    let mut r = n - m;
    let mut l = 0;
    let mut x = 0;
    for i in 1..=n {
        if x < b.len() && b[x] == i {
            if l >= (k - 1) / 2 && r >= (k - 1) / 2 {
                return true;
            }
            x += 1;
        } else {
            r -= 1;
            l += 1;
        }
    }
    false
}

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let k: usize = it.next().unwrap().parse().unwrap();
        let m: usize = it.next().unwrap().parse().unwrap();
        let b: Vec<usize> = (0..m).flat_map(|_| it.next().unwrap().parse()).collect();
        if solve(&b, n, k) {
            writeln!(out, "YES").ok();
        } else {
            writeln!(out, "NO").ok();
        }
    }
}

fn main() {
    run();
}
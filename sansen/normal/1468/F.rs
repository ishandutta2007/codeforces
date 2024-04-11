use std::io::*;

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
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
        let mut map = std::collections::BTreeMap::new();
        for _ in 0..n {
            let x: i64 = it.next().unwrap().parse().unwrap();
            let y: i64 = it.next().unwrap().parse().unwrap();
            let z: i64 = it.next().unwrap().parse().unwrap();
            let w: i64 = it.next().unwrap().parse().unwrap();
            let dx = z - x;
            let dy = w - y;
            let g = gcd(dx.abs(), dy.abs());
            *map.entry((dx / g, dy / g)).or_insert(0) += 1;
        }
        let mut ans = 0u64;
        for (&(dx, dy), &c) in map.iter() {
            map.get(&(-dx, -dy)).map(|p| ans += *p * c);
        }
        ans /= 2;
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
fn rand() -> usize {
    static mut X: usize = 5;
    unsafe {
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

use std::io::*;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: i64 = it.next().unwrap().parse().unwrap();
    let ax: i64 = it.next().unwrap().parse().unwrap();
    let ay: i64 = it.next().unwrap().parse().unwrap();
    let bx: i64 = it.next().unwrap().parse().unwrap();
    let by: i64 = it.next().unwrap().parse().unwrap();
    let s = (ax * by - ay * bx).abs();
    if s != n {
        println!("NO");
        return;
    }
    println!("YES");
    let (a, c, b, d) = (ax, ay, bx, by);
    let det = (a * d - b * c).abs();
    let mut set = std::collections::BTreeSet::new();
    let mut ans = vec![];
    for _ in 0..n {
        loop {
            let x = (rand() % 2000000) as i64;
            let y = (rand() % 2000000) as i64;
            let z = ((d * x - b * y) % det + det) % det;
            let w = ((-c * x + a * y) % det + det) % det;
            if set.insert((z, w)) {
                let p = a * z + b * w;
                let q = c * z + d * w;
                assert!(p % det == 0 && q % det == 0);
                ans.push((x, y));
                break;
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (x, y) in ans {
        writeln!(out, "{} {}", x, y).ok();
    }
}

fn main() {
    run();
}
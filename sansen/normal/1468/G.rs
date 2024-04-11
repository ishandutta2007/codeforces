use std::io::*;

fn dis(a: (i64, i64), b: (i64, i64)) -> f64 {
    (((a.0 - b.0).pow(2) + (a.1 - b.1).pow(2)) as f64).sqrt()
}

fn gcd(a: i64, b: i64) -> i64 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn dir(s: (i64, i64), t: (i64, i64)) -> (i64, i64) {
    let dx = t.0 - s.0;
    let dy = t.1 - s.1;
    let g = gcd(dx, dy);
    (dx / g, dy / g)
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let h: i64 = it.next().unwrap().parse().unwrap();
    let mut p = vec![(0i64, 0i64); n];
    for p in p.iter_mut() {
        p.0 = it.next().unwrap().parse().unwrap();
        p.1 = it.next().unwrap().parse().unwrap();
    }
    let s = (p[n - 1].0, p[n - 1].1 + h);
    let mut ans = 0f64;
    ans += dis(p[n - 1], p[n - 2]);
    let mut line = p[n - 2];
    for p in p.windows(2).rev().skip(1) {
        if (s.0 - line.0) * (p[0].1 - s.1) >= (s.1 - line.1) * (p[0].0 - s.0) {
            if dir(p[0], p[1]) == dir(line, s) {
                ans += dis(p[0], p[1]);
            } else {
                let (a, b, e) = {
                    let (a, b) = line;
                    let (c, d) = s;
                    (d - b, -(c - a), a * d - b * c)
                };
                let (c, d, f) = {
                    let (a, b) = p[0];
                    let (c, d) = p[1];
                    (d - b, -(c - a), a * d - b * c)
                };
                let mut det = a * d - b * c;
                let mut x = d * e - b * f;
                let mut y = -c * e + a * f;
                if det < 0 {
                    det = -det;
                    x = -x;
                    y = -y;
                }
                if p[0].0 * det <= x && x <= p[1].0 * det {
                    let x = x as f64 / det as f64;
                    let y = y as f64 / det as f64;
                    let (z, w) = p[0];
                    ans += ((z as f64 - x).powi(2) + (w as f64 - y).powi(2)).sqrt();
                }
            }
            line = p[0];
        }
    }
    println!("{:.7}", ans);
}

fn main() {
    run();
}
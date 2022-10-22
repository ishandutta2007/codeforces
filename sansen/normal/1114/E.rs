use std::io::Write;

fn read() -> i32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let v: i32 = s.trim().parse().unwrap();
    if v == -1 {
        std::process::exit(1);
    }
    v
}

fn query1(i: i32) -> i32 {
    println!("? {}", i);
    std::io::stdout().flush().ok();
    read()
}

fn query2(x: i32) -> i32 {
    println!("> {}", x);
    std::io::stdout().flush().ok();
    read()
}

struct RNG {
    x: u32,
}

impl RNG {
    fn new(seed: u32) -> RNG {
        RNG {
            x: seed,
        }
    }
    fn next(&mut self) -> u32 {
        let mut y = self.x;
        y = y ^ (y << 13);
        y = y ^ (y >> 17);
        y = y ^ (y << 5);
        self.x = y;
        y
    }
}

fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {a} else {gcd(b, a % b)}
}

fn run() {
    let n = read();
    let mut l = -1;
    let mut r = 1_000_000_000 + 1;
    while r - l > 1 {
        let m = (l + r) / 2;
        if query2(m) == 1 {
            l = m;
        } else {
            r = m;
        }
    }
    let max = r;
    let mut rng = RNG::new(2463534242);
    for _ in 0..1000 {
        rng.next();
    }
    let mut d = 0;
    for _ in 0..30 {
        let k = rng.next() % (n as u32) + 1;
        let v = max - query1(k as i32);
        d = gcd(d, v);
    }
    println!("! {} {}", max - (n - 1) * d, d);
}

fn main() {
    run();
}
use std::io::Write;

fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

struct RNG {
    x: usize,
}

impl RNG {
    fn new() -> Self {
        RNG {
            x: rand_memory()
        }
    }
    fn next(&mut self) -> usize {
        let x = &mut self.x;
        *x ^= *x << 13;
        *x ^= *x >> 17;
        *x ^= *x << 5;
        *x
    }
}

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |a: usize, b: usize| -> usize {
        assert!(cnt < 4269 && a != b && std::cmp::max(a, b) < n);
        cnt += 1;
        println!("? {} {}", a + 1, b + 1);
        std::io::stdout().flush().ok();
        read()
    };
    let mut p: Vec<usize> = (0..n).collect();
    let mut rng = RNG::new();
    for i in 1..n {
        let x = rng.next() % (i + 1);
        p.swap(i, x);
    }
    let mut x = 0;
    let mut val = !0usize;
    for y in (0..n).take(25) {
        if x != y {
            val &= query(p[x], p[y]);
        }
    }
    while val != 0 {
        let mut update = false;
        for i in (x + 1)..n {
            if query(p[x], p[i]) == val {
                x = i;
                for y in (0..n).take(25) {
                    if x != y {
                        val &= query(p[x], p[y]);
                    }
                }
                update = true;
                break;
            }
        }
        assert!(update || val == 0);
    }
    let mut ans = vec![0; n];
    for i in 0..n {
        if i != x {
            ans[p[i]] = query(p[i], p[x]);
        }
    }
    print!("!");
    for a in ans {
        print!(" {}", a);
    }
    println!();
}

fn main() {
    run();
}
fn read() -> Vec<u64> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    let (n, k) = {
        let a = read();
        (a[0], a[1])
    };
    let mut cnt = 0;
    let mut query = |q: u64| -> u64 {
        assert!(q < n);
        assert!(cnt < 1000);
        cnt += 1;
        println!("? {}", q + 1);
        read()[0]
    };
    let sq = (n as f64).sqrt() as u64 - 1;
    let mut x = 0;
    while query(x % n) >= k {
        x += sq;
    }
    let mut y = x + sq;
    while query(y % n) <= k {
        y += sq;
    }
    while y - x > 1 {
        let m = (y + x) / 2;
        if query(m % n) <= k {
            x = m;
        } else {
            y = m;
        }
    }
    if query(x % n) == k {
        println!("! {}", x % n + 1);
    } else {
        println!("! {}", y % n + 1);
    }
}

#[allow(dead_code)]
fn test() {
    let n = 20;
    let k = 2;
    let m = n / 2;
    let mut a = vec![k; n];
    for _ in 0..200 {
        println!("{:?}", a);
        let mut next = vec![0; n];
        for (i, a) in a.iter().enumerate() {
            if i != m {
                let l = *a / 2;
                let r = *a - l;
                next[(i + n - 1) % n] += l;
                next[(i + 1) % n] += r;
            }
        }
        next[m + 1] += a[m];
        a = next;
    }
}

fn main() {
//    test();
    run();
}
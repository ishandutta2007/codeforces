fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |l: usize, r: usize| -> usize {
        assert!(l < r && r <= n && cnt < 20);
        cnt += 1;
        println!("? {} {}", l, r);
        read()
    };
    let x = query(1, n);
    if x > 1 && query(1, x) == x {
        let mut l = 1;
        let mut r = x;
        while r - l > 1 {
            let m = (l + r) / 2;
            if query(m, x) == x {
                l = m;
            } else {
                r = m;
            }
        }
        println!("! {}", l);
    } else {
        let mut l = x;
        let mut r = n;
        while r - l > 1 {
            let m = (l + r) / 2;
            if query(x, m) == x {
                r = m;
            } else {
                l = m;
            }
        }
        println!("! {}", r);
    }
}

fn main() {
    run();
}
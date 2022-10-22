fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut ask = 0;
    let mut query = |x: usize| -> usize {
        assert!(1 <= x && x <= n);
        assert!(ask < 100);
        ask += 1;
        println!("? {}", x);
        read()
    };
    let mut l = 1;
    let mut r = n;
    while r - l > 1 {
        let m = (l + r) / 2;
        let a = query(m);
        let b = query(m + 1);
        if a < b {
            r = m;
        } else {
            l = m + 1;
        }
    }
    if l == r {
        println!("! {}", l);
    } else {
        let a = query(l);
        let b = query(r);
        if a < b {
            println!("! {}", l);
        } else {
            println!("! {}", r);
        }
    }
}

fn main() {
    run();
}
fn read() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().chars().collect()
}

fn run() {
    let n: usize = read().parse().unwrap();
    let inf = 1_000_000_000;
    let mut cnt = 0;
    let mut query = |x: i32, y: i32| -> bool {
        assert!(cnt < n && 0 <= x && x <= inf && 0 <= y && y <= inf);
        cnt += 1;
        println!("{} {}", x, y);
        read() == "white"
    };
    let origin = query(0, 0);
    if n == 1 {
        println!("1 0 1 1");
        return;
    }
    let right = query(inf, 0);
    if origin == right {
        let mut l = 0;
        let mut r = inf;
        for _ in 2..n {
            let m = (l + r) / 2;
            if query(0, m) == origin {
                l = m;
            } else {
                r = m;
            }
        }
        println!("{} {} {} {}", 0, l + 1, 1, l + 1);
    } else {
        let mut l = 0;
        let mut r = inf;
        for _ in 2..n {
            let m = (l + r) / 2;
            if query(m, 0) == origin {
                l = m;
            } else {
                r = m;
            }
        }
        println!("{} {} {} {}", l + 1, 0, l + 1, 1);
    }
}

fn main() {
    run();
}
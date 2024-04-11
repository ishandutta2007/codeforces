fn read() -> Vec<i64> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .flat_map(|s| s.parse())
        .collect()
}

fn run() {
    let (m, n) = {
        let a = read();
        (a[0], a[1])
    };
    let mut cnt = 0;
    let mut query = |x: i64| -> i64 {
        assert!(cnt < 60);
        cnt += 1;
        println!("{}", x);
        let v = read()[0];
        if v == 0 {
            std::process::exit(0);
        }
        assert!(v != -2);
        v
    };
    let mut p = vec![];
    for _ in 0..n {
        p.push(query(1));
    }
    let mut l = 1;
    let mut r = m + 1;
    for p in p.iter().cycle() {
        let mid = (l + r) / 2;
        if *p * query(mid) > 0 {
            l = mid;
        } else {
            r = mid;
        }
    }
}

fn main() {
    run();
}
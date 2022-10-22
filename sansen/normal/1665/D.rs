fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn solve() {
    let mut cnt = 0;
    let mut query = |a: usize, b: usize| -> usize {
        assert!(cnt < 30);
        assert!(a != b);
        assert!(a.min(b) >= 1);
        assert!(a.max(b) <= 2_000_000_000);
        cnt += 1;
        println!("? {} {}", a, b);
        read()
    };
    let mut a = 1;
    for i in 0..30 {
        let g = query(a, a + (1 << 30));
        if g.trailing_zeros() <= i {
            a += 1 << i;
        }
    }
    let ans = (1 << 30) - a;
    println!("! {}", ans);
}

fn main() {
    let t = read();
    for _ in 0..t {
        solve();
    }
}
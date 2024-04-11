fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn main() {
    let n = read();
    let mut cnt = 0;
    let mut query = |w: usize| -> usize {
        assert!(cnt < n + 30);
        cnt += 1;
        println!("? {}", w);
        read()
    };
    let mut ng = 0;
    let mut ok = 2000 * n + (n - 1);
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if query(mid) == 1 {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let sum = ok - (n - 1);
    let mut ans = ok;
    for h in 1..=n {
        let w = (sum + n - h + h - 1) / h;
        let res = query(w);
        if res > 0 {
            ans = ans.min(res * w);
        }
    }
    println!("! {}", ans);
}
use std::io::Write;

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |l: usize, u: usize, r: usize, d: usize| -> usize {
        assert!(cnt < 200);
        cnt += 1;
        assert!(l < r && r <= n && u < d && d <= n);
        println!("? {} {} {} {}", l + 1, u + 1, r, d);
        std::io::stdout().flush().ok();
        read()
    };
    let mut ask = vec![];
    {
        let mut l = 0;
        let mut r = n;
        while r - l > 1 {
            let mid = (l + r) / 2;
            if query(0, 0, mid, n) == 0 {
                l = mid;
            } else {
                r = mid;
            }
        }
        if r < n && query(0, 0, r, n) == 1 && query(r, 0, n, n) == 1 {
            ask.push((0, 0, r, n));
            ask.push((r, 0, n, n));
        }
    }
    if ask.is_empty() {
        let mut l = 0;
        let mut r = n;
        while r - l > 1 {
            let mid = (l + r) / 2;
            if query(0, 0, n, mid) == 0 {
                l = mid;
            } else {
                r = mid;
            }
        }
        if r < n && query(0, 0, n, r) == 1 && query(0, r, n, n) == 1 {
            ask.push((0, 0, n, r));
            ask.push((0, r, n, n));
        }
    }
    assert!(!ask.is_empty());
    let mut ans = vec![];
    for &(l, u, r, d) in ask.iter() {
        let mut ok = r;
        let mut ng = l;
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if query(l, u, mid, d) == 1 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        let r = ok;
        let mut ok = l;
        let mut ng = r;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if query(mid, u, r, d) == 1 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        let l = ok;
        let mut ok = d;
        let mut ng = u;
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if query(l, u, r, mid) == 1 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        let d = ok;
        let mut ok = u;
        let mut ng = d;
        while ng - ok > 1 {
            let mid = (ok + ng) / 2;
            if query(l, mid, r, d) == 1 {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        let u = ok;
        ans.push((l, u, r, d));
    }
    print!("!");
    for (l, u, r, d) in ans {
        print!(" {} {} {} {}", l + 1, u + 1, r, d);
    }
    println!();
}

fn main() {
    run();
}
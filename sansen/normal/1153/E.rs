fn read() -> u32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

use std::io::Write;

fn query(a: u32, b: u32, c: u32, d: u32) -> u32 {
    println!("? {} {} {} {}", a, b, c, d);
    std::io::stdout().flush().unwrap();
    read()
}

fn run() {
    let n = read();
    let mut ans = vec![];
    for i in (1..=n).rev() {
        let v = query(i, 1, i, n);
        if v % 2 == 0 {
            continue;
        }
        let mut l = 1;
        let mut r = n;
        while r - l > 0 {
            let m = (l + r) / 2;
            if query(i, l, i, m) % 2 == 0 {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans.push((i, l));
    }
    ans.sort();
    ans.dedup();
    for i in (1..n).rev() {
        if ans.len() == 2 {
            break;
        }
        let v = query(1, i, n, i);
        if v % 2 == 0 {
            continue;
        }
        let mut l = 1;
        let mut r = n;
        while r - l > 0 {
            let m = (l + r) / 2;
            if query(l, i, m, i) % 2 == 0 {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans.push((l, i));
        ans.sort();
        ans.dedup();
    }
    ans.sort();
    ans.dedup();
    if ans.len() < 2 {
        let mut l = 1;
        let mut r = n;
        while r - l > 0 {
            let m = (l + r) / 2;
            if query(l, n, m, n) % 2 == 0 {
                l = m + 1;
            } else {
                r = m;
            }
        }
        ans.push((l, n));
    }
    println!("! {} {} {} {}", ans[0].0, ans[0].1, ans[1].0, ans[1].1);
    std::io::stdout().flush().unwrap();
}

fn main() {
    run();
}
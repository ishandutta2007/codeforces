use std::io::*;

fn read() -> u64 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read() as usize;
    let mut a = vec![vec![0u64; n]; n];
    for i in 1..n {
        for j in (0..(n - 1)).rev() {
            let mut s = 1;
            for k in 0..i {
                s += a[k][0];
            }
            s -= a[i - 1][0];
            for k in 0..=(j + 1) {
                s += a[i - 1][k];
            }
            for k in (j + 1)..n {
                s += a[i][k];
            }
            for k in 0..i {
                s -= a[k][j];
            }
            for k in (j + 1)..n {
                s -= a[i][k];
            }
            a[i][j] = s;
            assert!(s <= 10u64.pow(16));
        }
    }
    let mut s = String::new();
    for a in a.iter() {
        for a in a.iter() {
            s.push_str(&format!("{} ", *a));
        }
        s.pop();
        s.push('\n');
    }
    print!("{}", s);
    std::io::stdout().flush().ok();
    let q = read();
    for _ in 0..q {
        let mut m = read();
        let mut pos = (n - 1, n - 1);
        let mut ans = vec![pos];
        while pos.0 > 0 && pos.1 > 0 {
            let mut s = 0;
            for i in 0..=pos.0 {
                s += a[i][pos.1 - 1];
            }
            if s <= m {
                pos.1 -= 1;
            } else {
                pos.0 -= 1;
            }
            m -= a[pos.0][pos.1];
            ans.push(pos);
        }
        while pos.0 > 0 {
            pos.0 -= 1;
            ans.push(pos);
        }
        while pos.1 > 0 {
            pos.1 -= 1;
            ans.push(pos);
        }
        ans.reverse();
        let mut s = String::new();
        for (a, b) in ans {
            s.push_str(&format!("{} {}\n", a + 1, b + 1));
        }
        print!("{}", s);
        std::io::stdout().flush().ok();
    }
}

fn main() {
    run();
}
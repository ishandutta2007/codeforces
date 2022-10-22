use std::io::*;
use std::cmp::*;

fn run() {
    let stdin = std::io::stdin();
    let mut reader = stdin.lock();
    let mut s = String::new();
    let mut read = || -> Vec<usize> {
        s.clear();
        reader.read_line(&mut s).unwrap();
        s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
    };
    let (n, m, k) = {
        let a = read();
        (a[0], a[1], a[2])
    };
    let size = n.next_power_of_two();
    let mut seg = vec![vec![]; 2 * size];
    for _ in 0..k {
        let (l, r, k) = {
            let a = read();
            (a[0], a[1], a[2] - 1)
        };
        seg[k + size].push((l, r));
    }
    for (_i, seg) in seg[size..].iter_mut().enumerate() {
        let mut a = seg.clone();
        a.sort();
        seg.clear();
        for (l, r) in a {
            if seg.last().map_or(false, |p| p.0 == l && p.1 <= r) {
                continue;
            }
            while seg.last().map_or(false, |p| p.0 <= l && r <= p.1) {
                seg.pop();
            }
            seg.push((l, r));
        }
    }
    for i in (1..size).rev() {
        let mut x = 0;
        let mut y = 0;
        let a = &seg[2 * i];
        let b = &seg[2 * i + 1];
        let mut c = vec![];
        while x < a.len() && y < b.len() {
            let (p, q) = a[x];
            let (r, s) = b[y];
            if p <= r {
                c.push((p, max(q, s)));
                x += 1;
            } else {
                c.push((r, max(q, s)));
                y += 1;
            }
        }
        c.sort();
        let seg = &mut seg[i];
        for (l, r) in c {
            if seg.last().map_or(false, |p| p.0 == l && p.1 <= r) {
                continue;
            }
            while seg.last().map_or(false, |p| p.0 <= l && r <= p.1) {
                seg.pop();
            }
            seg.push((l, r));
        }
    }
    for _ in 0..m {
        let (a, b, x, y) = {
            let a = read();
            (a[0] - 1, a[1], a[2], a[3])
        };
        let valid = |seg: &[(usize, usize)]| -> bool {
            let k = seg.binary_search(&(x, 0)).unwrap_err();
            k < seg.len() && seg[k].1 <= y
        };
        let mut l = a + size;
        let mut r = b + size;
        let mut ok = true;
        while l < r && ok {
            if l & 1 == 1 {
                ok &= valid(&seg[l]);
                l += 1;
            }
            if r & 1 == 1 {
                r -= 1;
                ok &= valid(&seg[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        let ans = if ok {
            "yes"
        } else {
            "no"
        };
        println!("{}", ans);
    }
}

fn main() {
    run();
}
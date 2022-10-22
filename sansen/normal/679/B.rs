// ---------- begin kth root ----------
// floor(a ^ (1 / k))
fn kth_root(a: u64, k: u64) -> u64 {
    assert!(k > 0);
    if a == 0 {
        return 0;
    }
    if k >= 64 {
        return 1;
    }
    if k == 1 {
        return a;
    }
    let valid = |x: u64| -> bool {
        let mut t = x;
        for _ in 1..k {
            let (val, ok) = t.overflowing_mul(x);
            if !(!ok && val <= a) {
                return false;
            }
            t = val;
        }
        true
    };
    let mut ok = 1;
    let mut ng = 2;
    while valid(ng) {
        ok = ng;
        ng *= 2;
    }
    while ng - ok > 1 {
        let mid = ok + (ng - ok) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    ok
}
// ---------- end kth root ----------

use std::cmp::*;

type Map = std::collections::BTreeMap<u64, (u64, u64)>;

fn calc(n: u64, map: &mut Map) -> (u64, u64) {
    if n == 0 {
        return (0, 0);
    }
    if let Some(v) = map.get(&n) {
        return *v;
    }
    let p = kth_root(n, 3);
    let v = p.pow(3);
    let (a, b) = calc(v - 1, map);
    let (c, d) = calc(n - v, map);
    let (c, d) = (c + 1, d + v);
    let ans = max((a, b), (c, d));
    map.insert(n, ans);
    ans
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let m: u64 = s.trim().parse().unwrap();
    let mut memo = Map::new();
    let (cnt, x) = calc(m, &mut memo);
    println!("{} {}", cnt, x);
}

fn main() {
    run();
}
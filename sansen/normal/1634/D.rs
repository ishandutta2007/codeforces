// i, j, k  max(a_i, a_j, a_k) - min(a_i, a_j, a_k) 
// 2
//
// N <= 3000
// a_i <= 10^9
// 2n-2
//
// 
//

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;

fn run() {
    let n = read();
    let mut map = Map::new();
    let mut cnt = 0;
    let mut query = |a: usize, b: usize, c: usize| -> usize {
        let mut x = [a, b, c];
        x.sort();
        assert!(1 <= x[0] && x[0] < x[1] && x[1] < x[2] && x[2] <= n);
        /*
        if let Some(&v) = map.get(&x) {
            return v;
        }
        */
        assert!(cnt < 2 * n - 2);
        cnt += 1;
        println!("? {} {} {}", x[0], x[1], x[2]);
        let res = read();
        map.insert(x, res);
        res
    };
    let mut v = query(1, 2, 3);
    let mut x = 3;
    for i in 4..=n {
        let u = query(1, 2, i);
        if u > v {
            v = u;
            x = i;
        }
    }
    let mut y = 2;
    for i in 3..=n {
        if i != x {
            let u = query(1, i, x);
            if u > v {
                v = u;
                y = i;
            }
        }
    }
    let z = (1..).find(|p| *p != x && *p != y && *p != 1).unwrap();
    let val = query(z, x, y);
    if val == v {
        println!("! {} {}", x, y);
    } else {
        let q = query(1, z, x);
        if q == v {
            println!("! {} {}", 1, x);
        } else {
            println!("! {} {}", 1, y);
        }
    }
}

fn main() {
    let t = read();
    for _ in 0..t {
        run();
    }
}
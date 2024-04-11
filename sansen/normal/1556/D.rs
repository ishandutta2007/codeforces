// 2n  k
// 3 <= n <= 10^4
// 1 <= k <= n
// x!= y a_x & a_y  a_x | a_y 
//
// k=1 
// a_0 & a_i
// a_0 | a_i
// n = 3
// 0 & 1
// 0 | 1
// 1 & 2
// 1 | 2
// 2 & 0
// 2 | 0
//
// a_0 
// a_1..a_n 
// a_0 

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    let (n, k) = {
        let a = read();
        (a[0], a[1])
    };
    let mut cnt = 0;
    let mut query = |op: &str, x: usize, y: usize| -> usize {
        assert!(cnt < 2 * n);
        cnt += 1;
        assert!(op == "and" || op == "or");
        assert!(x != y && x.max(y) < n);
        println!("{} {} {}", op, x + 1, y + 1);
        read()[0]
    };
    let w = 30;
    let mut p = vec![];
    let mut fix = vec![None; w];
    for i in 1..n {
        let a = query("and", 0, i);
        let b = query("or", 0, i);
        let mut v = 0;
        for i in 0..w {
            let x = a >> i & 1;
            let y = b >> i & 1;
            if x == y {
                fix[i] = Some(x);
            } else {
                v |= 1 << i;
            }
        }
        p.push(v);
    }
    let a = query("and", 1, 2);
    let b = query("or", 1, 2);
    for i in 0..w {
        if fix[i].is_none() {
            let x = a >> i & 1;
            let y = b >> i & 1;
            assert!(x == y);
            fix[i] = Some(x ^ 1);
        }
    }
    p.push(0);
    for (i, f) in fix.iter().enumerate() {
        let x = f.unwrap();
        for p in p.iter_mut() {
            *p ^= x << i;
        }
    }
    p.sort();
    println!("finish {}", p[k - 1]);
}

fn main() {
    run();
}
// 2n 
//

use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut memo = vec![];
    let mut query = |x: usize| -> usize {
        assert!(1 <= x && x <= n);
        assert!(cnt < 2 * n);
        println!("? {}", x);
        let res = read();
        memo.push((cnt, x, res));
        cnt += 1;
        res
    };
    let mut ans = vec![0; n + 1];
    let mut used = vec![false; n + 1];
    for x in 1..=n {
        if used[x] {
            continue;
        }
        let mut ord = vec![];
        let mut v = query(x);
        while !used[v] {
            used[v] = true;
            ord.push(v);
            v = query(x);
        }
        let pos = ord.iter().position(|v| *v == x).unwrap();
        let len = ord.len();
        ord.rotate_left(pos + 1);
        let mut last = x;
        for i in 0..len {
            ans[last] = ord[i];
            last = ord[i];
        }
    }
    let mut s = String::new();
    for i in 1..=n {
        s.push_str(&format!(" {}", ans[i]));
    }
    println!("!{}", s);
}

fn main() {
    let t = read();
    for _ in 0..t {
        run();
    }
}
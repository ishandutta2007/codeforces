use std::io::Write;

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .map(|s| s.parse().unwrap())
        .collect()
}

fn run() {
    let n = read()[0];
    let mut query_cnt = 0;
    let mut query = |w: &[usize]| -> Vec<usize> {
        assert!(query_cnt < 20);
        query_cnt += 1;
        let mut s = String::new();
        assert!(w.len() > 0 && w.len() <= n);
        s.push_str(&format!("{}\n", w.len()));
        let mut set = std::collections::BTreeSet::new();
        for w in w.iter() {
            assert!(!set.contains(w));
            set.insert(*w);
            s.push_str(&format!("{} ", *w + 1));
        }
        s.pop();
        println!("{}", s);
        std::io::stdout().flush().ok();
        read()
    };
    let mut ans = vec![std::usize::MAX; n];
    for i in 0..10 {
        if 1 << i >= n {
            break;
        }
        for p in 0..2 {
            let mut w = vec![];
            for j in 0..n {
                if j / (1 << i) % 2 == p {
                    w.push(j);
                }
            }
            let v = query(&w);
            for (i, v) in v.iter().enumerate() {
                if w.binary_search(&i).is_err() {
                    ans[i] = std::cmp::min(ans[i], *v);
                }
            }
        }
    }
    println!("-1");
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
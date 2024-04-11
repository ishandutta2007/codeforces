fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |c: usize| -> usize {
        assert!(1 <= c && c < n && cnt < 10);
        cnt += 1;
        println!("+ {}", c);
        read()
    };
    let mut cond = (1..n).collect::<Vec<_>>();
    let mut add = 0;
    while cond.len() > 1 {
        let mut next = (0, 0);
        for c in 1..n {
            let mut map = std::collections::BTreeMap::new();
            for cond in cond.iter() {
                *map.entry((*cond + add + c) / n).or_insert(0) += 1;
            }
            let v = *map.values().min().unwrap();
            if map.len() > 1 && next.0 < v {
                next = (v, c);
            }
        }
        add += next.1;
        let q = query(next.1);
        cond.retain(|v| (*v + add) / n == q);
    }
    println!("! {}", cond[0] + add);
}

fn main() {
    run();
}
use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let len: Vec<usize> = (0..3).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let n = len.iter().fold(0, |s, a| s + *a);
    let mut a = vec![];
    for len in len {
        let mut b = vec![];
        for _ in 0..len {
            let v: usize = it.next().unwrap().parse().unwrap();
            b.push(v);
        }
        b.sort();
        a.append(&mut b);
    }
    let mut dp = vec![0];
    for a in a {
        let k = dp.binary_search(&a).unwrap_err();
        if k == dp.len() {
            dp.push(a);
        } else {
            dp[k] = a;
        }
    }
    println!("{}", n + 1 - dp.len());
}

fn main() {
    run();
}
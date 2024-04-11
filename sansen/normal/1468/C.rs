use std::io::*;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let q: usize = it.next().unwrap().parse().unwrap();
    let mut ord = std::collections::BTreeSet::new();
    let mut money = std::collections::BTreeSet::new();
    let mut out = String::new();
    let mut cnt = 0i32;
    for _ in 0..q {
        let op: u8 = it.next().unwrap().parse().unwrap();
        if op == 1 {
            cnt += 1;
            let m: u32 = it.next().unwrap().parse().unwrap();
            ord.insert((cnt, m));
            money.insert((m, -cnt));
        } else if op == 2 {
            let (k, m) = *ord.iter().next().unwrap();
            ord.remove(&(k, m));
            money.remove(&(m, -k));
            out.push_str(&format!("{} ", k));
        } else {
            let (m, k) = *money.iter().rev().next().unwrap();
            ord.remove(&(-k, m));
            money.remove(&(m, k));
            out.push_str(&format!("{} ", -k));
        }
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
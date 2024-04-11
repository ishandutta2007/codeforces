use std::io::*;

fn query(s: &[char]) -> usize {
    let s: String = s.iter().map(|c| *c).collect();
    println!("{}", s);
    std::io::stdout().flush().ok();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    let v: i32 = s.trim().parse().unwrap();
    assert!(v >= 0);
    if v == 0 {
        std::process::exit(0);
    }
    v as usize
}

fn run() {
    let n = 300;
    let ca = n - query(&vec!['a'; n]);
    let cb = n - query(&vec!['b'; n]);
    let len = ca + cb;
    let mut d = cb;
    let mut s = vec!['a'; len];
    for i in (1..len).rev() {
        let mut t = s.clone();
        t[i] = 'b';
        let v = query(&t);
        if v < d {
            d = v;
            s = t;
        }
    }
    if d > 0 {
        s[0] = 'b';
    }
    query(&s);
}

fn main() {
    run();
}
use std::io::*;

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
}

fn ask(x: &[usize]) -> Vec<usize> {
    let mut out = String::new();
    out.push_str(&format!("? {}", x.len()));
    for x in x.iter() {
        out.push_str(&format!(" {}", *x));
    }
    println!("{}", out);
    std::io::stdout().flush().ok();
    read()
}

fn answer(x: &[usize]) {
    let mut out = String::new();
    out.push_str(&format!("!"));
    for x in x.iter() {
        out.push_str(&format!(" {}", *x));
    }
    println!("{}", out);
    std::io::stdout().flush().ok();
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    assert!(s.trim() == "Correct");
}

fn run() {
    let t: usize = read()[0];
    for _ in 0..t {
        let (n, k) = {
            let a = read();
            (a[0], a[1])
        };
        let mut id = vec![k; n + 1];
        for i in 0..k {
            let mut b = read();
            b.remove(0);
            for b in b.iter() {
                id[*b] = i;
            }
        }
        let all: Vec<_> = (1..=n).collect();
        let max = ask(&all)[0];
        let mut l = 1;
        let mut r = n + 1;
        while r - l > 1 {
            let mid = (l + r) / 2;
            let p: Vec<usize> = (l..mid).collect();
            if max == ask(&p)[0] {
                r = mid;
            } else {
                l = mid;
            }
        }
        let mut p = vec![];
        for i in 1..=n {
            if id[i] != id[l] {
                p.push(i);
            }
        }
        let s = ask(&p)[0];
        let mut ans = vec![max; k];
        if id[l] < k {
            ans[id[l]] = s;
        }
        answer(&ans);
    }
}

fn main() {
    run();
}
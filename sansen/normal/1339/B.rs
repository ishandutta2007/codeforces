use std::io::Read;
use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a: Vec<i32> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();
        a.sort();
        let mut ans = vec![];
        let mut f = 0;
        let mut b = a.len();
        while f + 1 < b {
            ans.push(a[f]);
            f += 1;
            b -= 1;
            ans.push(a[b]);
        }
        if f < b {
            ans.push(a[f]);
        }
        let mut s = String::new();
        ans.reverse();
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
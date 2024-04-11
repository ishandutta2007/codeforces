use std::io::Write;

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse::<usize>().unwrap()
}

fn query(a: usize, b: usize) -> usize {
    println!("? {} {}", a + 1, b + 1);
    std::io::stdout().flush().ok();
    read() - 1
}

fn run() {
    let n: usize = read();
    let mut g = vec![vec![]; n];
    for _ in 1..n {
        let mut s = String::new();
        std::io::stdin().read_line(&mut s).unwrap();
        let mut it = s.trim().split_whitespace();
        let a: usize = it.next().unwrap().parse().unwrap();
        let b: usize = it.next().unwrap().parse().unwrap();
        g[a - 1].push(b - 1);
        g[b - 1].push(a - 1);
    }
    let mut remove = vec![false; n];
    for _ in 0..(n / 2) {
        let mut a = vec![];
        for v in 0..n {
            if remove[v] {
                continue;
            }
            let mut deg = 0;
            for &u in g[v].iter() {
                if !remove[u] {
                    deg += 1;
                }
            }
            if deg == 0 {
                println!("! {}", v + 1);
                return;
            }
            if deg <= 1 {
                a.push(v);
            }
        }
        assert!(a.len() > 1);
        let (v, u) = (a[0], a[1]);
        let x = query(v, u);
        if x == v || x == u {
            println!("! {}", x + 1);
            return;
        }
        remove[u] = true;
        remove[v] = true;
    }
    for v in 0..n {
        if !remove[v] {
            println!("! {}", v + 1);
            return;
        }
    }
}

fn main() {
    run();
}
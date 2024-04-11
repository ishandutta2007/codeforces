use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let m: usize = it.next().unwrap().parse().unwrap();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a = vec![];
    for _ in 0..m {
        let s = it.next().unwrap().parse().unwrap();
        let mut b = vec![false; n];
        for _ in 0..s {
            let k: usize = it.next().unwrap().parse::<usize>().unwrap() - 1;
            b[k] = true;
        }
        a.push(b);
    }
    for i in 1..m {
        for j in 0..i {
            let mut ok = false;
            for k in 0..n {
                if a[i][k] && a[j][k] {
                    ok = true;
                    break;
                }
            }
            if !ok {
                println!("impossible");
                return;
            }
        }
    }
    println!("possible");
}

fn main() {
    run();
}
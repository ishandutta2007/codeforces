use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let mut a = vec![];
    for s in it {
        let mut len = 0;
        for c in s.chars() {
            if c == '-' {
                a.push(len + 1);
                len = 0;
            } else {
                len += 1;
            }
        }
        a.push(len + 1);
    }
    *a.last_mut().unwrap() -= 1;
    let valid = |w: usize| -> bool {
        let mut sum = 0;
        let mut cnt = 0;
        for a in a.iter() {
            if *a > w {
                return false;
            }
            if sum + *a <= w {
                sum += *a;
            } else {
                cnt += 1;
                sum = *a;
            }
        }
        cnt += 1;
        cnt <= n
    };
    let mut ng = 0;
    let mut ok = 1_000_000;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        if valid(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    println!("{}", ok);
}

fn main() {
    run();
}
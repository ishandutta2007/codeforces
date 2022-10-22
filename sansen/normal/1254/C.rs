use std::io::Write;

fn read() -> i64 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn query_one(x: i64, y: i64, z: i64) -> i64 {
    println!("1 {} {} {}", x, y, z);
    std::io::stdout().flush().ok();
    read()
}

fn query_two(x: i64, y: i64, z: i64) -> i64 {
    println!("2 {} {} {}", x, y, z);
    std::io::stdout().flush().ok();
    read()
}

fn run() {
    let n: i64 = read();
    let x = 1;
    let mut y = 2;
    for i in 3..=n {
        let v = query_two(x, y, i);
        if v < 0 {
            y = i;
        }
    }
    let mut s = vec![];
    for i in 2..=n {
        if i == y {
            continue;
        }
        let v = query_one(x, y, i);
        s.push((v, i));
    }
    s.sort();
    let mut q = std::collections::VecDeque::new();
    q.push_back(1);
    q.push_back(y);
    let len = s.len();
    for _ in 1..len {
        assert!(s.len() >= 2);
        let (_, a) = s[0];
        let (_, b) = s[1];
        let v = query_two(a, x, b);
        if v > 0 {
            q.push_front(a);
        } else {
            q.push_back(a);
        }
        s.reverse();
        s.pop();
        s.reverse();
    }
    assert!(s.len() == 1);
    q.push_back(s[0].1);
    while *q.front().unwrap() != 1 {
        let v = q.pop_front().unwrap();
        q.push_back(v);
    }
    let mut out = String::new();
    out.push('0');
    for v in q.iter() {
        out.push(' ');
        out.push_str(&v.to_string());
    }
    println!("{}", out);
}

fn main() {
    run();
}
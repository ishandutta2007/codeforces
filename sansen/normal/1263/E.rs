use std::io::Read;
use std::cmp::*;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    // 
    let mut left = vec![(0, 0, 0, 0); 1];
    let mut now = 0;
    let mut right = vec![(0, 0, 0, 0); n + 1];
    let s: String = it.next().unwrap().chars().collect();
    let mut out = String::new();
    for c in s.chars() {
        match c {
            'L' => {
                if left.len() > 1 {
                    let p = *right.last().unwrap();
                    let x = p.0 - now;
                    right.push((x, -now, max(x, p.2), min(x, p.3)));
                    now = left.pop().unwrap().1;
                }
            },
            'R' => {
                let p = *left.last().unwrap();
                let x = p.0 + now;
                left.push((x, now, max(x, p.2), min(x, p.3)));
                now = -right.pop().unwrap().1;
            },
            '(' => {
                now = 1;
            },
            ')' => {
                now = -1;
            },
            _ => {
                now = 0;
            },
        }
        let l = *left.last().unwrap();
        let r = *right.last().unwrap();
        let ans = if l.3 >= 0 && r.3 >= 0 && l.0 + now - r.0 == 0 {
            max(l.2, r.2)
        } else {
            -1
        };
        out.push_str(&format!("{} ", ans));
    }
    out.pop();
    println!("{}", out);
}

fn main() {
    run();
}
use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let s: Vec<char> = it.next().unwrap().chars().collect();
        let mut set = std::collections::BTreeSet::new();
        let mut x = 0i32;
        let mut y = 0i32;
        let d = [(-1, 0), (1, 0), (0, -1), (0, 1)];
        for &c in s.iter() {
            for &d in d.iter() {
                set.insert((x + d.0, y + d.1));
            }
            match c {
                'U' => y += 1,
                'D' => y -= 1,
                'L' => x -= 1,
                _ => x += 1,
            }
        }
        let mut ans = (0, 0);
        for &p in set.iter() {
            if p == (0, 0) {
                continue;
            }
            let mut x = 0;
            let mut y = 0;
            for c in s.iter() {
                let save = (x, y);
                match c {
                    'U' => y += 1,
                    'D' => y -= 1,
                    'L' => x -= 1,
                    _ => x += 1,
                }
                if (x, y) == p {
                    x = save.0;
                    y = save.1;
                }
            }
            if (x, y) == (0, 0) {
                ans = p;
                break;
            }
        }
        writeln!(out, "{} {}", ans.0, ans.1).ok();
    }
}

fn main() {
    run();
}
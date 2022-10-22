use std::io::*;

fn run() {
    let stdin = std::io::stdin();
    let mut stdin = std::io::BufReader::new(stdin.lock());
    let mut s = String::new();
    let mut read = || -> Vec<usize> {
        s.clear();
        stdin.read_line(&mut s).unwrap();
        s.trim()
            .split_whitespace()
            .flat_map(|s| s.parse())
            .collect()
    };
    let (q, a, c) = {
        let a = read();
        (a[0], a[1], a[2])
    };
    let mut parent = vec![vec![0]];
    let mut gold = vec![(a, c)];
    for _ in 0..q {
        let op = read();
        if op[0] == 1 {
            let (p, a, c) = (op[1], op[2], op[3]);
            let mut dp = vec![p];
            while let Some(p) = parent[*dp.last().unwrap()].get(dp.len() - 1) {
                dp.push(*p);
            }
            parent.push(dp);
            gold.push((a, c));
        } else {
            parent.push(vec![]);
            gold.push((0, 0));
            let (v, mut w) = (op[1], op[2]);
            let save = w;
            let mut ans = 0;
            while w > 0 && gold[v].0 > 0 {
                let mut pos = v;
                for i in (0..parent[v].len()).rev() {
                    if i >= parent[pos].len() {
                        continue;
                    }
                    let p = parent[pos][i];
                    if gold[p].0 > 0 {
                        pos = p;
                    }
                }
                let (a, c) = gold[pos];
                let x = w.min(a);
                w -= x;
                gold[pos].0 -= x;
                ans += x as u64 * c as u64;
            }
            println!("{} {}", save - w, ans);
        }
    }
}

fn main() {
    run();
}
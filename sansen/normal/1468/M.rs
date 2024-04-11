use std::io::*;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut z = vec![];
        let mut a = vec![];
        for _ in 0..n {
            let k: usize = it.next().unwrap().parse().unwrap();
            let mut p = vec![];
            for _ in 0..k {
                let v: usize = it.next().unwrap().parse().unwrap();
                p.push(v);
            }
            p.sort();
            z.extend_from_slice(&p);
            a.push(p);
        }
        z.sort();
        z.dedup();
        let mut g = vec![std::collections::BTreeSet::new(); n + z.len()];
        for (i, a) in a.into_iter().enumerate() {
            for a in a.iter() {
                let k = z.binary_search(a).unwrap();
                g[i].insert(k + n);
                g[k + n].insert(i);
            }
        }
        let mut h = std::collections::BinaryHeap::new();
        for (i, g) in g.iter().enumerate() {
            h.push((g.len(), i));
        }
        let mut elem = vec![None; n + z.len()];
        let mut ans = None;
        while let Some((d, v)) = h.pop() {
            if d != g[v].len() {
                continue;
            }
            let p = std::mem::take(&mut g[v]);
            for &u in p.iter() {
                g[u].remove(&v);
                h.push((g[u].len(), u));
                for &w in g[u].iter() {
                    if elem[w].is_some() {
                        let x = elem[w].unwrap();
                        ans = Some((v, u, w, x));
                    }
                    elem[w] = Some(u);
                }
            }
            for &w in p.iter().flat_map(|u| g[*u].iter()) {
                elem[w] = None;
            }
        }
        if let Some((a, b, c, d)) = ans {
            let mut p = [a, b, c, d];
            p.sort();
            writeln!(out, "{} {}", p[0] + 1, p[1] + 1).ok();
        } else {
            writeln!(out, "-1").ok();
        }
    }
}

fn main() {
    run();
}
use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    let n: usize = it.next().unwrap().parse().unwrap();
    let a: Vec<u32> = (0..n).map(|_| it.next().unwrap().parse().unwrap()).collect();
    let mut front = vec![];
    let mut back = vec![];
    for i in 0..(1 << 15) {
        let mut b = Vec::with_capacity(n);
        let mut c = Vec::with_capacity(n);
        for &a in &a {
            b.push(((a & ((1 << 15) - 1)) ^ i).count_ones() as u8);
            c.push(((a >> 15) ^ i).count_ones() as u8);
        }
        front.push((b, i));
        back.push((c, i));
    }
    front.sort();
    front.dedup_by_key(|p| p.0.clone());
    back.sort();
    back.dedup_by_key(|p| p.0.clone());
    for bit in 0..=30 {
        for p in &front {
            let mut s = Vec::with_capacity(n);
            for &c in p.0.iter() {
                if c > bit {
                    break;
                }
                s.push(bit - c);
            }
            if s.len() < n {
                continue;
            }
            if let Ok(k) = back.binary_search_by(|p| p.0.cmp(&s)) {
                let x = (back[k].1 << 15) + p.1;
                println!("{}", x);
                return;
            }
        }
    }
    println!("-1");
}

fn main() {
    run();
}
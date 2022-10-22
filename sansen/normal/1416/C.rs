use std::io::Read;

fn run() {
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.trim().split_whitespace();
    it.next();
    let a: Vec<usize> = it.map(|s| s.parse().unwrap()).collect();
    let mut p = vec![a.clone()];
    let mut x = 0;
    let mut ans_inv = 0;
    for i in (0..30).rev() {
        let mut cnt = [0u64; 2];
        let mut q = vec![];
        for a in p {
            let mut inv = [0; 2];
            let mut c = [0; 2];
            let mut b = vec![vec![]; 2];
            for a in a {
                let x = a >> i & 1;
                inv[x] += c[x ^ 1];
                c[x] += 1;
                b[x].push(a);
            }
            for b in b {
                if b.len() > 1 {
                    q.push(b);
                }
            }
            cnt[0] += inv[0];
            cnt[1] += inv[1];
        }
        p = q;
        let y = (cnt[1] < cnt[0]) as usize;
        ans_inv += cnt[y];
        x |= y << i;
    }
    println!("{} {}", ans_inv, x);
}

fn main() {
    run();
}
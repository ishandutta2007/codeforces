fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn valid(p: &[usize]) -> bool {
    let mut used = vec![false; p.len()];
    for p in p.iter() {
        if *p >= used.len() || used[*p] {
            return false;
        }
        used[*p] = true;
    }
    true
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |x: usize, y: usize| -> usize {
        assert!(cnt < 2 * n && x < n && y < n);
        cnt += 1;
        println!("? {} {}", x, y);
        read()
    };
    let mut a = vec![0; n];
    for (i, a) in a.iter_mut().enumerate() {
        *a = query(0, i);
    }
    let mut b = vec![0; n];
    for (i, b) in b.iter_mut().enumerate() {
        *b = query(i, 0);
    }
    let mut cnt = 0;
    let mut sample = vec![];
    for s in 0..n {
        let mut p = vec![0; n];
        let mut q = vec![0; n];
        p[0] = s;
        for (q, a) in q.iter_mut().zip(a.iter()) {
            *q = *a ^ s;
        }
        for (p, b) in p.iter_mut().zip(b.iter()) {
            *p = *b ^ q[0];
        }
        if p[0] != s || !valid(&p) || !valid(&q) {
            continue;
        }
        let mut ok = true;
        for i in 0..n {
            ok &= p[q[i]] == i;
        }
        if ok {
            cnt += 1;
            sample = p;
        }
    }
    println!("!\n{}", cnt);
    for (i, p) in sample.iter().enumerate() {
        if i > 0 {
            print!(" ");
        }
        print!("{}", *p);
    }
    println!();
}

fn main() {
    run();
}
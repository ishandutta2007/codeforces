use std::io::Write;
use std::collections::BTreeSet;

fn rand() -> usize {
    static mut X: usize = 2463534242;
    unsafe {
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
}

fn run() {
    let t = read()[0];
    for _ in 0..t {
        let (n, k) = {
            let a = read();
            (a[0], a[1])
        };
        type Set = BTreeSet<usize>;
        assert!(k <= n / 2);
        let query = |a: &Set, b: &Set| -> u8 {
            assert!(a.iter().all(|a| !b.contains(a)), "query dupplicate");
            let mut out = String::new();
            out.push_str(&format!("? {} {}\n", a.len(), b.len()));
            for a in [a, b].iter() {
                assert!(a.len() > 0, "empty query");
                for a in a.iter() {
                    assert!(*a < n, "query range");
                    out.push_str(&format!("{} ", *a + 1));
                }
                out.pop();
                out.push('\n');
            }
            print!("{}", out);
            std::io::stdout().flush().ok();
            let mut res = String::new();
            std::io::stdin().read_line(&mut res).unwrap();
            match res.trim().chars().next().unwrap() {
                'F' => 0,
                'S' => 1,
                'E' => 2,
                _ => unreachable!("answer invalid"),
            }
        };
        let mut max = Set::new();
        max.insert(0);
        let mut unknown = (1..n).collect::<Set>();
        for _ in 0..26 {
            let n = unknown.len();
            if n == 0 {
                break;
            }
            let x = *unknown.iter().nth(rand() % n).unwrap();
            unknown.remove(&x);
            let mut a = Set::new();
            a.insert(*max.iter().next().unwrap());
            let mut b = Set::new();
            b.insert(x);
            let res = query(&a, &b);
            if res == 0 {
            } else if res == 1 {
                max = b;
            } else {
                max.insert(x);
            }
        }
        let mut stone = max;
        let mut unknown = (0..n).collect::<Set>();
        for s in stone.iter() {
            unknown.remove(s);
        }
        let mut elem = Set::new();
        while elem.is_empty() {
            let size = std::cmp::min(stone.len(), unknown.len());
            assert!(size > 0);
            let mut a = Set::new();
            let mut b = Set::new();
            for s in stone.iter().take(size) {
                a.insert(*s);
            }
            for u in unknown.iter().take(size) {
                b.insert(*u);
            }
            if query(&a, &b) == 0 {
                elem = b;
            } else {
                for b in b {
                    unknown.remove(&b);
                    stone.insert(b);
                }
            }
        }
        while elem.len() > 1 {
            let size = elem.len() / 2;
            let mut a = Set::new();
            let mut b = Set::new();
            for s in stone.iter().take(size) {
                a.insert(*s);
            }
            for u in elem.iter().take(size) {
                b.insert(*u);
            }
            if query(&a, &b) == 0 {
                elem = b.into_iter().collect();
            } else {
                for b in b {
                    elem.remove(&b);
                }
            }
        }
        let ans = *elem.iter().next().unwrap();
        println!("! {}", ans + 1);
        std::io::stdout().flush().ok();
    }
}

fn main() {
    run();
}
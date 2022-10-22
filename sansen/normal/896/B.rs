// 1 <= n*ceil(c/2) <= m
// 
//
// 

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    let (n, m, c) = {
        let a = read();
        (a[0], a[1], a[2])
    };
    let mut p = vec![0; n + 2];
    p[n + 1] = c + 1;
    for _ in 0..m {
        if p[1] > 0 && p.windows(2).all(|p| p[0] <= p[1]) {
            break;
        }
        let v = read()[0];
        if 2 * v <= c {
            let mut x = 1;
            while p[x] > 0 && v >= p[x] {
                x += 1;
            }
            p[x] = v;
            println!("{}", x);
        } else {
            let mut x = n;
            while p[x] > 0 && v <= p[x] {
                x -= 1;
            }
            p[x] = v;
            println!("{}", x);
        }
    }
    assert!(p[1] > 0 && p.windows(2).all(|p| p[0] <= p[1]));
}

fn main() {
    run();
}
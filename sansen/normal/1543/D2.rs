fn read() -> Vec<i32> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    let (n, k) = {
        let a = read();
        (a[0] as usize, a[1] as usize)
    };
    let mut len = 0;
    let mut m = n - 1;
    while m > 0 {
        len += 1;
        m /= k;
    }
    let len = len;
    let mut map = vec![vec![0; k]; len];
    for map in map.iter_mut() {
        for (i, map) in map.iter_mut().enumerate() {
            *map = i;
        }
    }
    for i in 0..n {
        let mut a = vec![0; len];
        let mut m = i;
        for (a, map) in a.iter_mut().zip(&map) {
            *a = map[m % k];
            m /= k;
        }
        let mut v = 0;
        for a in a.iter().rev() {
            v = k * v + *a;
        }
        println!("{}", v);
        let res = read()[0];
        assert!(res >= 0);
        if res == 1 {
            return;
        }
        for (map, a) in map.iter_mut().zip(a) {
            for map in map.iter_mut() {
                *map = (a + k - *map) % k;
            }
        }
    }
    unreachable!();
}

fn main() {
    let t = read()[0];
    for _ in 0..t {
        run();
    }
}
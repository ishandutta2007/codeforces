// max(min(x, p_i), min(x + 1, p_j))
// min(max(x, p_i), max(x + 1, p_j))
//  floor(3 / 2 * n) + 30
// 
// 1 <= x <= n - 1
// n >= 3
// t=1 x=n-1 
// max(min(n - 1, p_i), min(n, p_j))
// p_j  n 
// n
// t=2  x = 1, min(max(1, p_i), max(2, n)) 
// 
// 3n/2+30?
// max(min(n - 1, p_i), min(n, p_j))
// n-1 
// n-1 
// swap

fn read() -> i32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let v = s.trim().parse().unwrap();
    assert!(v >= 0);
    v
}

fn run() {
    let n = read() as usize;
    let mut cnt = 0;
    let mut query = |t: usize, i: usize, j: usize, x: usize| -> usize {
        assert!(cnt < 3 * n / 2 + 30);
        cnt += 1;
        assert!(1 <= t && t <= 2);
        assert!(i != j && 1 <= x && x <= n - 1);
        assert!(i.max(j) < n);
        println!("? {} {} {} {}", t, i + 1, j + 1, x);
        read() as usize
    };
    let mut max = n + 1;
    let mut x = 1;
    while x < n {
        let mut a = x;
        let mut b = x - 1;
        let mut v = query(1, a, b, n - 1);
        if v == n - 1 {
            v = query(1, b, a, n - 1);
            std::mem::swap(&mut a, &mut b);
        }
        if v == n {
            max = b;
            break;
        }
        x += 2;
    }
    if max == n + 1 {
        max = n - 1;
    }
    let mut ans = vec![0; n];
    ans[max] = n;
    for i in 0..n {
        if i != max {
            ans[i] = query(2, i, max, 1);
        }
    }
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("! {}", s);
}

fn main() {
    let t = read();
    for _ in 0..t {
        run();
    }
}
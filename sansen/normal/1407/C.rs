use std::io::Write;

// 2N
// N
// 
//
// 1
// 1 mod k = 1, k mod 1 = 0
//
// p_k N-1
// 2p_i, p_j 

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |x: usize, y: usize| -> usize {
        cnt += 1;
        assert!(cnt <= 2 * n);
        assert!(x != y);
        assert!(1 <= x && x <= n);
        assert!(1 <= y && y <= n);
        println!("? {} {}", x, y);
        read()
    };
    let mut a = vec![None; n + 1];
    let mut pos = 1;
    for i in 2..=n {
        let x = query(i, pos);
        let y = query(pos, i);
        if x < y {
            a[pos] = Some(y);
            pos = i;
        } else {
            a[i] = Some(x);
        }
    }
    let mut ans = String::new();
    for a in a.iter().skip(1) {
        if let Some(v) = *a {
            ans.push_str(&format!(" {}", v));
        } else {
            ans.push_str(&format!(" {}", n));
        }
    }
    println!("!{}", ans);
}

fn main() {
    run();
}
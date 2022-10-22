fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |l: usize, r: usize| -> usize {
        assert!(1 <= l && l < r && r <= n && cnt < n);
        cnt += 1;
        println!("? {} {}", l, r);
        read()
    };
    let mut s = vec![0; n + 1];
    for i in 2..=n {
        s[i] = query(1, i);
    }
    let v = query(2, n);
    let mut a = vec![0; n + 1];
    a[1] = s[n] - v;
    for i in (3..=n).rev() {
        a[i] = s[i] - s[i - 1];
    }
    a[2] = s[2] - a[1];
    let mut s = String::from("!");
    for a in a.iter().skip(1) {
        s.push_str(&format!(" {}", *a));
    }
    println!("{}", s);
}

fn main() {
    run();
}
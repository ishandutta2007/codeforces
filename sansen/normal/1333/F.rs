fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let n: usize = s.trim().parse().unwrap();
    let mut used = vec![false; n + 1];
    let mut ans = vec![];
    for i in (1..=n).rev() {
        let mut j = n / i * i;
        while j >= 2 * i {
            if !used[j] {
                used[j] = true;
                ans.push(i);
            }
            j -= i;
        }
    }
    ans.reverse();
    let mut s = String::new();
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
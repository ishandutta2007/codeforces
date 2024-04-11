// n <= 100
//
// 
// p+a k
// a_n = n - 1, a_k = n 
// p_n - 1 
// 
// p_n 

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut cnt = 0;
    let mut query = |a: &[usize]| -> usize {
        assert!(cnt < 2 * n);
        cnt += 1;
        assert!(a.iter().all(|a| 1 <= *a && *a <= n));
        let mut s = String::from("?");
        for a in a.iter() {
            s.push_str(&format!(" {}", *a));
        }
        println!("{}", s);
        read()
    };
    let mut ans = vec![0; n];
    for k in 1..n {
        let mut a = vec![1; n];
        a[n - 1] += k;
        let res = query(&a);
        if res == 0 {
            ans[n - 1] = n + 1 - k;
            break;
        }
        ans[res - 1] = k;
    }
    if ans[n - 1] == 0 {
        ans[n - 1] = 1;
    }
    for k in 1..n {
        let mut a = vec![n; n];
        a[n - 1] -= k;
        let res = query(&a);
        if res == 0 {
            break;
        }
        ans[res - 1] = !k + 1;
    }
    for i in 0..(n - 1) {
        ans[i] += ans[n - 1];
    }
    let mut s = String::from("!");
    for a in ans.iter() {
        s.push_str(&format!(" {}", *a));
    }
    println!("{}", s);
}

fn main() {
    run();
}
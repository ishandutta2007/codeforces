//  <= 1000
// 5
// 
// 4
// 
//
// 
//
// x=y=6 
// 
// BAOK?

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().map(|s| s.parse().unwrap()).collect()
}

fn run() {
    let t = read()[0];
    for _ in 0..t {
        let n = read()[0];
        let mut g = vec![vec![]; n + 1];
        for _ in 1..n {
            let e = read();
            let (a, b) = (e[0], e[1]);
            g[a].push(b);
            g[b].push(a);
        }
        let _a = read()[0];
        let mut x = read();
        x.sort();
        let _b = read()[0];
        let y = read();
        let mut cnt = 0;
        let mut query = |c: char, v: usize| -> usize {
            assert!(cnt < 5 && 1 <= v && v <= n && (c == 'A' || c == 'B'));
            cnt += 1;
            println!("{} {}", c, v);
            read()[0]
        };
        let v = query('B', y[0]);
        let mut dp = vec![n; n + 1];
        dp[v] = 0;
        let mut q = std::collections::VecDeque::new();
        q.push_back(v);
        while let Some(v) = q.pop_front() {
            let d = dp[v] + 1;
            for &u in g[v].iter() {
                if dp[u] > d {
                    dp[u] = d;
                    q.push_back(u);
                }
            }
        }
        let v = dp.iter().enumerate().filter(|p| x.binary_search(&p.0).is_ok()).min_by_key(|p| p.1).unwrap().0;
        if y.contains(&query('A', v)) {
            println!("C {}", v);
        } else {
            println!("C -1");
        }
    }
}

fn main() {
    run();
}
// ---------- begin chmin, chmax ----------
pub trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .flat_map(|s| s.parse())
        .collect()
}

fn run() {
    let (n, k) = {
        let a = read();
        (a[0], a[1])
    };
    let mut cnt = 0;
    let mut query = |x: &[usize]| -> usize {
        let mut y = vec![];
        y.extend_from_slice(&x);
        y.sort();
        y.dedup();
        assert!(y.len() == k);
        assert!(y[k - 1] < n);
        assert!(cnt < 500);
        cnt += 1;
        let s = y
            .iter()
            .map(|s| (s + 1).to_string())
            .collect::<Vec<_>>()
            .join(" ");
        println!("? {}", s);
        read()[0]
    };
    let inf = 2 * n + 1;
    let mut dp = vec![inf; n + 1];
    dp[n] = 0;
    let mut q = std::collections::VecDeque::new();
    q.push_back(n);
    while let Some(v) = q.pop_front() {
        let d = dp[v] + 1;
        for i in 0..=(n - v).min(k) {
            let j = k - i;
            if j <= v && dp[v + i - j].chmin(d) {
                q.push_back(v + i - j);
            }
        }
    }
    if dp[0] == inf {
        println!("-1");
        return;
    }
    let mut off = (0..n).collect::<Vec<_>>();
    let mut on = vec![];
    let mut v = 0;
    let mut ans = 0;
    while v != n {
        for i in 0..=(n - v).min(k) {
            let j = k - i;
            if j <= v && dp[v + i - j] + 1 == dp[v] {
                let mut a = off.split_off(n - v - i);
                let mut b = on.split_off(v - j);
                let x = a.iter().chain(b.iter()).cloned().collect::<Vec<_>>();
                ans ^= query(&x);
                off.append(&mut b);
                on.append(&mut a);
                v = v + i - j;
                break;
            }
        }
    }
    println!("! {}", ans);
}

fn main() {
    run();
}
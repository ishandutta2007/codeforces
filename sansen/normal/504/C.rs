// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}
// ---------- end input macro ----------

fn run() {
    input! {
        n: usize,
        a: [usize1; n],
    }
    let mut cnt = vec![0; n];
    a.iter().for_each(|a| cnt[*a] ^= 1);
    if cnt.iter().sum::<u32>() > 1 {
        println!("0");
        return;
    }
    if a.iter().zip(a.iter().rev()).all(|a| *a.0 == *a.1) {
        let n = n as u64;
        println!("{}", n * (n + 1) / 2);
        return;
    }
    let x = a.iter().zip(a.iter().rev()).position(|a| *a.0 != *a.1).unwrap();
    let mut a = a;
    let mut ans = 0u64;
    for _ in 0..2 {
        let mut ng = x + 1;
        let mut ok = n;
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            let mut a = a.clone();
            let mut cnt = vec![0; n];
            let mut two = std::collections::BTreeSet::new();
            for a in a[x..mid].iter_mut() {
                cnt[*a] += 1;
                if cnt[*a] == 2 {
                    two.insert(*a);
                }
                *a = n;
            }
            let mut valid = true;
            for i in 0..n {
                if a[i] < n && a[n - i - 1] < n {
                    valid &= a[i] == a[n - 1 - i];
                    continue;
                }
                if a[i] == n && a[n - i - 1] == n {
                    if i == n - i - 1 {
                        break;
                    }
                    if two.is_empty() {
                        valid = false;
                        break;
                    }
                    let x = *two.iter().next().unwrap();
                    a[i] = x;
                    a[n - i - 1] = x;
                    cnt[x] -= 2;
                    if cnt[x] >= 2 {
                        two.insert(x);
                    }
                } else {
                    let y = a[i] ^ a[n - i - 1] ^ n;
                    if cnt[y] == 0 {
                        valid = false;
                        break;
                    }
                    a[i] = y;
                    a[n - i - 1] = y;
                    cnt[y] -= 1;
                    if cnt[y] <= 1 {
                        two.remove(&y);
                    }
                }
            }
            if valid {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ans += (x + 1) as u64 * (n - ok + 1) as u64;
        a.reverse();
    }
    ans -= (x as u64 + 1).pow(2);
    println!("{}", ans);
}

fn main() {
    run();
}
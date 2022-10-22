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

//  2 * n - 1
//  n * (n + 1) / 2
// 
// 
// kk
// 
// 1
// ...
// 
// 
// , 
// 
//
//  = 

fn run() {
    input! {
        n: usize,
        s: u64,
    }
    let m = n as u64;
    if s < 2 * m - 1 || m * (m + 1) / 2 < s {
        println!("No");
        return;
    }
    println!("Yes");
    if s == m * (m + 1) / 2 {
        let mut s = String::new();
        for i in 1..n {
            s.push_str(&format!("{} ", i));
        }
        s.pop();
        println!("{}", s);
        return;
    }
    let mut ng = 0;
    let mut ok = n - 1;
    while ok - ng > 1 {
        let mid = (ok + ng) / 2;
        let mut m = n as u64;
        let mut sum = 0;
        let mut sub = 1;
        while m > 0 {
            sum += m;
            m = m.saturating_sub(sub);
            sub *= mid as u64;
        }
        if sum <= s {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let deg = ok as u64;
    let calc = |h: &[u64], rem: usize| -> u64 {
        let mut rem = rem as u64;
        let mut c = 1;
        let mut sum = 0;
        for h in h.iter() {
            if rem == 0 {
                break;
            }
            sum += rem;
            rem = rem.saturating_sub(c - *h);
            c *= deg;
        }
        sum
    };
    let mut hist = vec![0; n];
    let mut sum = 1;
    hist[0] = 1;
    let mut x = 1;
    let mut rem = n - 1;
    loop {
        hist[x] += 1;
        sum += (x + 1) as u64;
        if sum + calc(&hist, rem - 1) > s {
            hist[x] -= 1;
            sum -= (x + 1) as u64;
            break;
        }
        x += 1;
        rem -= 1;
    }
    x -= 1;
    while rem > 0 {
        hist[x] += 1;
        sum += (x + 1) as u64;
        if sum + calc(&hist, rem - 1) > s {
            hist[x] -= 1;
            sum -= (x + 1) as u64;
            x -= 1;
        } else {
            rem -= 1;
        }
    }
    let mut parent = vec![0; n];
    let mut prev = vec![0];
    let mut d = vec![0; n];
    let mut x = 1;
    for i in 1..n {
        let mut now = vec![];
        for _ in 0..hist[i] {
            now.push(x);
            if d[*prev.last().unwrap()] == deg {
                prev.pop();
            }
            let p = *prev.last().unwrap();
            parent[x] = p;
            d[p] += 1;
            x += 1;
        }
        prev = now;
    }
    let mut s = String::new();
    for i in 1..n {
        s.push_str(&format!("{} ", parent[i] + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
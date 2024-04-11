//https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8 
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

//

// 0 + 1 + ... + n
fn sum(n: u64) -> u64 {
    n * (n + 1) / 2
}

fn run() {
    input! {
        n: usize,
        m: usize,
        a: u64,
        b: u64,
        c: u64,
        e: [(usize, usize); m],
    }
    let mut ans = 0u64;
    let size = n as u64;
    // 
    for i in 0..size {
        ans += (size - 1 - i) * (size - 2 - i) / 2 * a * i;
        ans += i * (size - 1 - i) * b * i;
        ans += i * (i - 1) / 2 * c * i;
    }
    // 1
    let mut e = e;
    for e in e.iter_mut() {
        if e.0 > e.1 {
            std::mem::swap(&mut e.0, &mut e.1);
        }
        let x = e.0 as u64;
        let y = e.1 as u64;
        let mut v = 0;
        v += a * sum(x - 1) + x * (x * b + y * c);
        v += b * (sum(y - 1) - sum(x)) + (y - x - 1) * (x * a + y * c);
        v += c * (sum(size - 1) - sum(y)) + (size - 1 - y) * (x * a + y * b);
        ans -= v;
    }
    // 2
    let mut g = vec![vec![]; n];
    for &(a, b) in e.iter() {
        g[a].push(b);
        g[b].push(a);
    }
    for (v, g) in g.iter().enumerate() {
        let mut small = vec![];
        let mut large = vec![];
        for &u in g.iter() {
            if u < v {
                small.push(u as u64);
            } else {
                large.push(u as u64);
            }
        }
        small.sort();
        large.sort();
        let v = v as u64;
        if small.len() > 0 {
            let mut sum = small[0] * a;
            let mut cnt = 1;
            for &u in small.iter().skip(1) {
                ans += sum + cnt * (u * b + v * c);
                sum += u * a;
                cnt += 1;
            }
        }
        if large.len() > 0 {
            let mut sum = large[0] * b;
            let mut cnt = 1;
            for &u in large.iter().skip(1) {
                ans += sum + cnt * (u * c + v * a);
                sum += u * b;
                cnt += 1;
            }
        }
        let l = small.iter().sum::<u64>() * a;
        let r = large.iter().sum::<u64>() * c;
        let x = small.len() as u64;
        let y = large.len() as u64;
        ans += l * y + r * x + b * v * x * y;
    }
    // 3
    let mut dag = vec![vec![]; n];
    let key = |v: usize| (g[v].len(), v);
    for e in e.iter_mut() {
        if key(e.0) > key(e.1) {
            std::mem::swap(&mut e.0, &mut e.1);
        }
        dag[e.0].push(e.1);
    }
    let mut elem = vec![false; n];
    for &(x, y) in e.iter() {
        dag[y].iter().for_each(|u| elem[*u] = true);
        for &u in dag[x].iter() {
            if elem[u] {
                let p = std::cmp::min(x, std::cmp::min(y, u));
                let r = std::cmp::max(x, std::cmp::max(y, u));
                let q = x ^ y ^ u ^ p ^ r;
                ans -= p as u64 * a + q as u64 * b + r as u64 * c;
            }
        }
        dag[y].iter().for_each(|u| elem[*u] = false);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
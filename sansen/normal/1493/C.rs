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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        ask: [(usize, usize, bytes); t],
    }
    for (n, k, mut s) in ask {
        if n % k != 0 {
            writeln!(out, "-1").ok();
            continue;
        }
        let mut cnt = [0; 26];
        for s in s.iter() {
            cnt[(s - b'a') as usize] += 1;
        }
        if cnt.iter().all(|c| *c % k == 0) {
            let ans = s.iter().map(|c| *c as char).collect::<String>();
            writeln!(out, "{}", ans).ok();
            continue;
        }
        while let Some(x) = s.pop() {
            let x = (x - b'a') as usize;
            cnt[x] -= 1;
            let q = cnt.iter().map(|c| (*c + k - 1) / k).sum::<usize>();
            if q > n / k {
                continue;
            }
            if q == n / k {
                let mut elem = [false; 26];
                for (elem, c) in elem.iter_mut().zip(cnt.iter()) {
                    if *c % k != 0 {
                        *elem = true;
                    }
                }
                if let Some(y) = elem[(x + 1)..].iter().position(|e| *e) {
                    let p = x + 1 + y;
                    s.push(p as u8 + b'a');
                    cnt[p] += 1;
                    while s.len() < n {
                        let x = cnt.iter().position(|c| *c % k != 0).unwrap();
                        s.push(b'a' + x as u8);
                        cnt[x] += 1;
                    }
                    break;
                }
            } else if x != 25 {
                s.push((x + 1) as u8 + b'a');
                cnt[x + 1] += 1;
                while cnt.iter().map(|c| (*c + k - 1) / k).sum::<usize>() < n / k {
                    s.push(b'a');
                    cnt[0] += 1;
                }
                while s.len() < n {
                    let x = cnt.iter().position(|c| *c % k != 0).unwrap();
                    s.push(b'a' + x as u8);
                    cnt[x] += 1;
                }
                break;
            }
        }
        let ans = s.iter().map(|c| *c as char).collect::<String>();
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
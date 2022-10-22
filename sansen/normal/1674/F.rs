use std::io::Write;

fn run() {
    input! {
        h: usize,
        w: usize,
        q: usize,
        s: [bytes; h],
        ask: [(usize1, usize1); q],
    }
    let mut s = transpose(s);
    let mut cnt = vec![0; s.len()];
    for (cnt, s) in cnt.iter_mut().zip(s.iter()) {
        for s in s.iter() {
            if *s == b'*' {
                *cnt += 1;
            }
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (x, y) in ask {
        let (x, y) = (y, x);
        if s[x][y] == b'*' {
            cnt[x] -= 1;
        } else {
            cnt[x] += 1;
        }
        s[x][y] ^= b'*' ^ b'.';
        let sum = cnt.iter().sum::<usize>();
        let w = s[0].len();
        let mut ans = cnt.iter().take(sum / w).fold(0, |s, a| s + w - *a);
        let rem = sum % w;
        if rem > 0 {
            ans += s[sum / w].iter().take(rem).filter(|c| **c == b'.').count();
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

// ---------- begin transpose ----------
pub fn transpose<T>(a: Vec<Vec<T>>) -> Vec<Vec<T>> {
    if a.is_empty() {
        return a;
    }
    let h = a.len();
    let w = a[0].len();
    assert!(a.iter().all(|a| a.len() == w));
    let mut ta: Vec<_> = (0..w).map(|_| Vec::with_capacity(h)).collect();
    for a in a {
        for (ta, a) in ta.iter_mut().zip(a) {
            ta.push(a);
        }
    }
    ta
}
// ---------- end transpose ----------
// ---------- begin input macro ----------
// reference: https://qiita.com/tanakh/items/0ba42c7ca36cd29d0ac8
#[macro_export]
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

#[macro_export]
macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

#[macro_export]
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
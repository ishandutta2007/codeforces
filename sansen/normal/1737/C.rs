use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [(usize, [(usize, usize); 4]); t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, p) in ask {
        let t = p[3];
        let mut p = p[..3].iter().cloned().collect::<Vec<_>>();
        let mut a = vec![(1, 1), (1, 2), (2, 1)];
        let mut ok = true;
        for _ in 0..4 {
            a.sort();
            p.sort();
            ok &= a != p;
            a.iter_mut().for_each(|a| *a = (n + 1 - a.1, a.0));
        }
        let mut ans = "NO";
        if p.iter().any(|p| *p == t) {
            ans = "YES";
        }
        if ok && p.iter().any(|p| (p.0 % 2, p.1 % 2) == (t.0 % 2, t.1 % 2)) {
            ans = "YES";
        }
        if !ok {
            for i in 0..3 {
                for j in 0..i {
                    if p[i].0 == p[j].0 && t.0 == p[i].0 {
                        ans = "YES";
                    }
                    if p[i].1 == p[j].1 && t.1 == p[i].1 {
                        ans = "YES";
                    }
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}

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
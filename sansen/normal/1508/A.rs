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
        t: usize,
        ask: [(usize, bytes, bytes, bytes); t],
    }
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for (n, a, b, c) in ask {
        let a = [a, b, c];
        let mut x = [0; 3];
        let mut ans = String::new();
        while x.iter().filter(|p| **p < 2 * n).count() == 3 {
            let mut cnt = [0; 2];
            for (a, x) in a.iter().zip(x.iter()) {
                if *x < 2 * n {
                    cnt[(a[*x] - b'0') as usize] += 1;
                }
            }
            let c = if cnt[0] >= cnt[1] {
                b'0'
            } else {
                b'1'
            };
            ans.push(c as char);
            for (a, x) in a.iter().zip(x.iter_mut()) {
                if *x < 2 * n && a[*x] == c {
                    *x += 1;
                }
            }
        }
        if x.iter().filter(|p| **p < 2 * n).count() == 2 {
            let mut y = x.iter().position(|x| *x < 2 * n).unwrap();
            for i in 0..3 {
                if x[i] != 2 * n && x[i] > x[y] {
                    y = i;
                }
            }
            for i in x[y]..(2 * n) {
                ans.push(a[y][i] as char);
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
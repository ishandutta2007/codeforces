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
        ask: [(usize, usize, usize); t],
    }
    let m = ask.iter().map(|p| p.1).max().unwrap();
    let mut f = (0..=m).collect::<Vec<_>>();
    for i in (2..).take_while(|p| p * p <= m) {
        if f[i] == i {
            for j in (i..).take_while(|j| j * i <= m) {
                f[j * i] = i;
            }
        }
    }
    let calc = |mut x: usize, res: &mut Vec<(usize, usize)>| {
        res.clear();
        res.push((1, 1));
        while x > 1 {
            let p = f[x];
            while x % p == 0 {
                x /= p;
            }
            for i in 0..res.len() {
                let (a, b) = res[i];
                res.push((a * p, !b + 1));
            }
        }
    };
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    let mut memo = vec![];
    for (x, p, k) in ask {
        calc(p, &mut memo);
        let count = |n: usize| -> usize {
            let mut res = 0;
            for &(d, sign) in memo.iter() {
                res += n / d * sign;
            }
            res
        };
        let sub = count(x);
        let mut ng = x;
        let mut ok = 2 * x;
        while count(ok) - sub < k {
            ng = ok;
            ok *= 2;
        }
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if count(mid) - sub < k {
                ng = mid;
            } else {
                ok = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
    }
}

fn main() {
    run();
}
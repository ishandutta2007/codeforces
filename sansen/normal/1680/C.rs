use std::io::Write;

fn run() {
    input! {
        t: usize,
        s: [bytes; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for mut s in s {
        for _ in 0..2 {
            while s.last().map_or(false, |c| *c == b'0') {
                s.pop();
            }
            s.reverse();
        }
        if s.iter().all(|c| *c == b'1') {
            writeln!(out, "0").ok();
            continue;
        }
        let mut cnt = vec![0; s.len() + 1];
        let mut pos = vec![];
        for (i, c) in s.iter().enumerate().rev() {
            cnt[i] = cnt[i + 1];
            if *c == b'1' {
                cnt[i] += 1;
            } else {
                pos.push(i);
            }
        }
        pos.reverse();
        let mut ng = 0;
        let mut ok = s.len() - cnt[0];
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            let mut can = false;
            for i in (mid - 1)..pos.len() {
                let mut one = 0;
                if i > mid - 1 {
                    one += cnt[0] - cnt[pos[i - mid]];
                }
                if i + 1 < pos.len() {
                    one += cnt[pos[i + 1]];
                }
                can |= one <= mid;
            }
            if can {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        writeln!(out, "{}", ok).ok();
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
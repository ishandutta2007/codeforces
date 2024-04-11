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
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

// 

use std::io::Write;

fn run() {
    input! {
        t: usize,
        ask: [u64; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for n in ask {
        let mut ans = vec![];
        let mut now = 1;
        let mut cnt = 1;
        while now + 4 * cnt <= n {
            ans.push(cnt);
            cnt *= 2;
            now += cnt;
        }
        if now + 2 * cnt >= n {
            ans.push(n - now - cnt);
        } else if now + 3 * cnt < n {
            let x = std::cmp::min((n - (now + 2 * cnt)) / 2, cnt);
            ans.push(x);
            cnt += x;
            now += cnt;
            ans.push(n - now - cnt);
        } else {
            ans.push(0);
            now += cnt;
            if now < n {
                ans.push(n - now - cnt);
            }
        }
        let mut s = String::new();
        s.push_str(&format!("{}\n", ans.len()));
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
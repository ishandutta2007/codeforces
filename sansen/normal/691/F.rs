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
        n: usize,
        a: [usize; n],
        m: usize,
        ask: [usize; m],
    }
    let w = 3_000_000;
    let mut cnt = vec![0u64; w + 1];
    for a in a {
        cnt[a] += 1;
    }
    let mut ans = vec![0u64; w + 1];
    let mut sum = 0;
    let mut j = w;
    for i in 1..=w {
        while i * j >= w {
            sum += cnt[j];
            j -= 1;
        }
        ans[w] += sum * cnt[i];
    }
    for i in 1..=w {
        for j in 1.. {
            if i * j >= w {
                break;
            }
            ans[i * j] += cnt[i] * cnt[j];
        }
    }
    for i in 1..=w {
        let k = i.saturating_mul(i);
        if k > w {
            ans[w] -= cnt[i];
        } else {
            ans[k] -= cnt[i];
        }
    }
    for i in (1..w).rev() {
        ans[i] += ans[i + 1];
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for p in ask {
        writeln!(out, "{}", ans[p]).ok();
    }
}

fn main() {
    run();
}
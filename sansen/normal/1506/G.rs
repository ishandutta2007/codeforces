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
    input! {
        t: usize,
        ask: [bytes; t],
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    for s in ask {
        let mut index = vec![std::collections::VecDeque::new(); 26];
        for (i, &c) in s.iter().enumerate() {
            let k = (c - b'a') as usize;
            index[k].push_back(i);
        }
        let mut ans = String::new();
        while let Some(k) = index.iter().rposition(|p| !p.is_empty()) {
            for i in (0..=k).rev() {
                if index[i].is_empty() {
                    continue;
                }
                let x = index[i][0];
                let mut ok = true;
                for (j, index) in index.iter().enumerate() {
                    if j == i {
                        continue;
                    }
                    ok &= index.back().map_or(true, |p| *p > x);
                }
                if ok {
                    ans.push((b'a' + i as u8) as char);
                    index[i].clear();
                    for index in index.iter_mut() {
                        while index.front().map_or(false, |p| *p < x) {
                            index.pop_front();
                        }
                    }
                    break;
                }
            }
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
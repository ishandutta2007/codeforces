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

use std::io::Write;

fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        p: [(usize, chars); t],
    }
    let op = "abacaba".chars().collect::<Vec<_>>();
    let count = |s: &[char]| -> usize {
        let mut cnt = 0;
        for i in 0..(s.len() - 6) {
            let mut ok = true;
            for j in 0..7 {
                ok &= s[i + j] == op[j];
            }
            if ok {
                cnt += 1;
            }
        }
        cnt
    };
    for (n, mut s) in p {
        let cnt = count(&s);
        if cnt > 1 {
            writeln!(out, "No").ok();
            continue;
        }
        let mut ans = String::new();
        if cnt == 1 {
            ans.push_str("Yes\n");
        } else {
            let mut find = false;
            for i in 0..(n - 6) {
                let mut ok = true;
                for j in 0..7 {
                    ok &= s[i + j] == op[j] || s[i + j] == '?';
                }
                if ok {
                    let mut t = s.clone();
                    for j in 0..7 {
                        t[i + j] = op[j];
                    }
                    for c in t.iter_mut() {
                        if *c == '?' {
                            *c = 'z';
                        }
                    }
                    if count(&t) == 1 {
                        find = true;
                        s = t;
                        break;
                    }
                }
            }
            if find {
                ans.push_str("Yes\n");
            } else {
                writeln!(out, "No").ok();
                continue;
            }
        }
        for c in s.iter_mut() {
            if *c == '?' {
                *c = 'z';
            }
        }
        for c in s {
            ans.push(c);
        }
        writeln!(out, "{}", ans).ok();
    }
}

fn main() {
    run();
}
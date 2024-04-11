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
        ask: [(usize, bytes, bytes); t],
    }
    for (n, a, b) in ask {
        let mut ans = vec![];
        let mut l = 0;
        let mut r = n;
        let mut pos = 0;
        for (i, &b) in b.iter().enumerate().skip(1).rev() {
            if pos == 0 {
                if a[r - 1] == b {
                    r -= 1;
                } else {
                    if a[l] == b {
                        ans.push(1);
                    }
                    ans.push(i + 1);
                    l += 1;
                    pos ^= 1;
                }
            } else {
                if a[l] != b {
                    l += 1;
                } else {
                    if a[r - 1] != b {
                        ans.push(1);
                    }
                    ans.push(i + 1);
                    r -= 1;
                    pos ^= 1;
                }
            }
        }
        if pos == 0 {
            if a[r - 1] == b[0] {
            } else {
                ans.push(1);
            }
        } else {
            if a[r - 1] != b[0] {
            } else {
                ans.push(1);
            }
        }
        /*
        let mut a = a;
        for &x in ans.iter() {
            for a in a.iter_mut().take(x) {
                *a ^= b'0' ^ b'1';
            }
            a[..x].reverse();
        }
        assert!(a == b);
        */
        let mut s = String::new();
        s.push_str(&format!("{}", ans.len()));
        for a in ans {
            s.push_str(&format!(" {}", a));
        }
        writeln!(out, "{}", s).ok();
    }
}

fn main() {
    run();
}
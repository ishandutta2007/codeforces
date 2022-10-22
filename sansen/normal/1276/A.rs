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
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        t: usize,
        s: [chars; t],
    }
    for s in s {
        let mut ans = vec![];
        let mut s = s;
        let n = s.len();
        for i in 5..=n {
            if s[(i - 5)..i] == ['t', 'w', 'o', 'n', 'e'] {
                ans.push(i - 3);
                s[i - 3] = '*';
            }
        }
        for i in 3..=n {
            if s[(i - 3)..i] == ['t', 'w', 'o'] {
                ans.push(i - 2);
                s[i - 2] = '*';
            }
        }
        for i in 3..=n {
            if s[(i - 3)..i] == ['o', 'n', 'e'] {
                ans.push(i - 2);
                s[i - 2] = '*';
            }
        }
        writeln!(out, "{}", ans.len()).ok();
        for (i, &a) in ans.iter().enumerate() {
            if i > 0 {
                write!(out, " ").ok();
            }
            write!(out, "{}", a + 1).ok();
        }
        writeln!(out, "").ok();
    }
}

fn main() {
    run();
}
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
        a: [chars; t],
    }
    for a in a {
        let mut odd = vec![];
        let mut even = vec![];
        for c in a {
            let d: usize = c as usize - '0' as usize;
            if d & 1 == 0 {
                even.push(d);
            } else {
                odd.push(d);
            }
        }
        let mut i = 0;
        let mut j = 0;
        let mut ans = vec![];
        while i < odd.len() && j < even.len() {
            if odd[i] < even[j] {
                ans.push(odd[i]);
                i += 1;
            } else {
                ans.push(even[j]);
                j += 1;
            }
        }
        while i < odd.len() {
            ans.push(odd[i]);
            i += 1;
        }
        while j < even.len() {
            ans.push(even[j]);
            j += 1;
        }
        for d in ans {
            write!(out, "{}", d).ok();
        }
        write!(out, "\n").ok();
    }
}

fn main() {
    run();
}
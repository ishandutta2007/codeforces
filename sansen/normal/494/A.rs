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
        s: bytes,
    }
    let cond = |b: bool| {
        if !b {
            println!("-1");
            std::process::exit(0);
        }
    };
    let mut s = s;
    let x = s.iter().rposition(|c| *c == b'#').unwrap();
    let mut ans = vec![];
    let mut cnt = 0i32;
    for i in 0..x {
        if s[i] == b'(' {
            cnt += 1;
        } else {
            cnt -= 1;
            if s[i] == b'#' {
                ans.push(1);
            }
            s[i] = b')';
        }
        cond(cnt >= 0);
    }
    let mut need = 0;
    for i in ((x + 1)..s.len()).rev() {
        if s[i] == b')' {
            need += 1;
        } else {
            need -= 1;
        }
        cond(need >= 0);
    }
    cond(cnt - need > 0);
    ans.push(cnt - need);
    for a in ans {
        println!("{}", a);
    }
}

fn main() {
    run();
}
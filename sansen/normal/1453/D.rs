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
        ask: [u64; t],
    }
    let mut a = vec![];
    for n in 1.. {
        let pow = 1u64 << n;
        let mut s = 0;
        for i in 1..=n {
            s += i * (pow >> i);
        }
        s += n * (pow >> n);
        if s <= 1_000_000_000_000_000_000 {
            a.push((n, s));
        } else {
            break;
        }
    }
    for mut n in ask {
        let mut ans = vec![1];
        for &(k, v) in a.iter().rev() {
            while n >= v {
                n -= v;
                for _ in 1..k {
                    ans.push(0);
                }
                ans.push(1);
            }
        }
        if n > 0 {
            println!("-1");
        } else {
            ans.pop();
            println!("{}", ans.len());
            let mut s = String::new();
            for a in ans {
                s.push_str(&format!("{} ", a));
            }
            s.pop();
            println!("{}", s);
        }
    }
}

fn main() {
    run();
}
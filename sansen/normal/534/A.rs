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
        n: usize,
    }
    if n <= 2 {
        println!("1\n1");
    } else if n == 3 {
        println!("2\n1 3");
    } else if n == 4 {
        println!("4\n2 4 1 3");
    } else {
        let m = (n + 1) / 2;
        let a = (1..=m).collect::<Vec<_>>();
        let b = ((m + 1)..=n).collect::<Vec<_>>();
        let mut ans = vec![];
        for i in 0..b.len() {
            ans.push(a[i]);
            ans.push(b[i]);
        }
        if b.len() < a.len() {
            ans.push(a[b.len()]);
        }
        println!("{}", ans.len());
        let mut s = String::new();
        for a in ans {
            s.push_str(&format!("{} ", a));
        }
        s.pop();
        println!("{}", s);
    }
}

fn main() {
    run();
}
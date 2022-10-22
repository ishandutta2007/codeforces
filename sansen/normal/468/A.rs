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
        n: i64,
    }
    if n <= 3 {
        println!("NO");
        return;
    }
    println!("YES");
    let mut out = String::new();
    if n % 2 == 0 {
        out.push_str(&format!("2 * 3 = 6\n"));
        out.push_str(&format!("6 * 4 = 24\n"));
        out.push_str(&format!("24 * 1 = 24\n"));
        let mut x = 5;
        while x <= n {
            out.push_str(&format!("{} - {} = 1\n", x + 1, x));
            out.push_str(&format!("24 * 1 = 24\n"));
            x += 2;
        }
    } else {
        out.push_str(&format!("5 * 3 = 15\n"));
        out.push_str(&format!("2 * 4 = 8\n"));
        out.push_str(&format!("15 + 8 = 23\n"));
        out.push_str(&format!("23 + 1 = 24\n"));
        let mut x = 6;
        while x <= n {
            out.push_str(&format!("{} - {} = 1\n", x + 1, x));
            out.push_str(&format!("24 * 1 = 24\n"));
            x += 2;
        }
    }
    print!("{}", out);
}

fn main() {
    run();
}
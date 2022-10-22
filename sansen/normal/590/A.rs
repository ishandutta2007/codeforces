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
        a: [u8; n],
    }
    let mut a = a;
    let v = a[0];
    a.insert(0, v);
    let v = a[n];
    a.push(v);
    let mut ans = 0;
    for i in 1..(a.len() - 1) {
        if a[i] == a[i - 1] && a[i] != a[i + 1] {
            let mut x = i + 1;
            while a[x] != a[x - 1] {
                x += 1;
            }
            let v = a[i];
            if v == a[x] {
                ans = ans.max((x - i) / 2);
                a[i..=x].iter_mut().for_each(|a| *a = v);
            } else {
                ans = ans.max((x - i) / 2 - 1);
                a[(i + 1)..(x - 1)].sort();
                if v == 1 {
                    a[(i + 1)..(x - 1)].reverse();
                }
            }
        }
    }
    println!("{}", ans);
    let mut s = String::new();
    a.remove(0);
    a.pop();
    for a in a {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
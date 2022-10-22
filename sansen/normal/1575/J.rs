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
        h: usize,
        w: usize,
        n: usize,
        a: [[u8; w]; h],
        ask: [usize1; n],
    }
    let mut a = a;
    let mut fix = vec![h; w];
    let mut used = vec![false; w];
    let mut c = vec![];
    let mut s = String::new();
    for x in ask {
        let mut y = x;
        let mut x = 0;
        while x < fix[y] {
            if !used[y] {
                used[y] = true;
                c.push(y);
            }
            if a[x][y] == 2 {
                x += 1;
            } else if a[x][y] == 1 {
                a[x][y] = 2;
                y += 1;
            } else {
                a[x][y] = 2;
                y -= 1;
            }
        }
        for y in c.drain(..) {
            used[y] = false;
            while fix[y] > 0 && a[fix[y] - 1][y] == 2 {
                fix[y] -= 1;
            }
        }
        s.push_str(&format!("{} ", y + 1));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
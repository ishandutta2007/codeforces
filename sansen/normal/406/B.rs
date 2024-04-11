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
        x: [usize; n],
    }
    let s = 1_000_000;
    let mut used = vec![false; s + 1];
    for x in x.iter() {
        used[*x] = true;
    }
    let mut y = vec![];
    let mut cnt = 0;
    for i in 1..=(s / 2) {
        match (used[i], used[s + 1 - i]) {
            (false, false) => (),
            (true, true) => cnt += 1,
            (true, false) => {
                used[s + 1 - i] = true;
                y.push(s + 1 - i);
            },
            (false, true) => {
                used[i] = true;
                y.push(i);
            },
        }
    }
    for i in 1..=(s / 2) {
        if cnt > 0 && !used[i] && !used[s + 1 - i] {
            y.push(i);
            y.push(s + 1 - i);
            cnt -= 1;
        }
    }
    assert!(cnt == 0);
    println!("{}", y.len());
    y.sort();
    let mut s = String::new();
    for y in y.iter() {
        s.push_str(&format!("{} ", *y));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
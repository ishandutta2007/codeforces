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

fn dfs(a: &[u64], k: usize, sup: bool, used: u64, b: &mut Vec<u64>) {
    if k == a.len() {
        b.push(used);
        return;
    }
    let y = if !sup {
        a[k]
    } else {
        6
    };
    for i in 0..=y {
        if used >> i & 1 == 0 {
            dfs(a, k + 1, sup || i < a[k], used | (1 << i), b);
        }
    }
}

fn run() {
    input! {
        n: u64,
        m: u64,
    }
    let mut a = vec![];
    let mut x = m - 1;
    if x == 0 {
        a.push(0);
    } else {
        while x > 0 {
            a.push(x % 7);
            x /= 7;
        }
    }
    a.reverse();
    let mut b = vec![];
    dfs(&a, 0, false, 0, &mut b);
    let sa = a;
    let mut a = vec![];
    let mut x = n - 1;
    if x == 0 {
        a.push(x);
    } else {
        while x > 0 {
            a.push(x % 7);
            x /= 7;
        }
    }
    if a.len() + sa.len() > 7 {
        println!("0");
        return;
    }
    a.reverse();
    let mut c = vec![];
    dfs(&a, 0, false, 0, &mut c);
    let mut ans = 0;
    for b in b.iter() {
        for c in c.iter() {
            if *b & *c == 0 {
                ans += 1;
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
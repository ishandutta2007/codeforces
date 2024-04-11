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

fn run() {
    input! {
        n: usize,
        ini: i32,
        p: [(i32, i32); n],
    }
    let mut q = vec![];
    let mut r = vec![];
    for (a, b) in p {
        if b >= 0 {
            q.push((a, b));
        } else {
            r.push((a, -b));
        }
    }
    q.sort();
    r.sort_by(|a, b| {
        let x = std::cmp::max(a.0, b.0 + a.1);
        let y = std::cmp::max(b.0, a.0 + b.1);
        x.cmp(&y)
    });
    let mut now = ini;
    let mut ans = 0;
    for (a, b) in q {
        if now >= a {
            ans += 1;
            now += b;
        }
    }
    let mut dp = vec![0; (now + 1) as usize];
    for (a, b) in r {
        let a = a as usize;
        let b = b as usize;
        for x in std::cmp::max(a, b)..=(now as usize) {
            dp[x - b] = std::cmp::max(dp[x - b], dp[x] + 1);
        }
    }
    let v = dp.iter().max().unwrap();
    ans += v;
//    println!("{}", ans);
    if ans == n {println!("YES");} else { println!("NO");}
}

fn main() {
    run();
}
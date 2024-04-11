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

fn run() {
    input! {
        n: usize,
        s: usize1,
        a: [usize; n],
    }
    let mut a = a;
    let mut add = 0;
    if a[s] != 0 {
        a[s] = 0;
        add = 1;
    }
    if n == 1 {
        println!("{}", add);
        return;
    }
    let mut sum = vec![0; n + 1];
    let mut empty = vec![1; n + 1];
    for a in a {
        sum[a] += 1;
        empty[a] = 0;
    }
    for i in (0..n).rev() {
        sum[i] += sum[i + 1];
        empty[i] += empty[i + 1];
    }
    let mut ans = n;
    for i in 1..n {
        let mut val = 0;
        val += sum[i + 1] + sum[0] - sum[1] - 1;
        if val < empty[0] - empty[i + 1] {
            val += empty[0] - empty[i + 1] - val;
        }
        ans = std::cmp::min(ans, val);
    }
    ans += add;
    println!("{}", ans);
}

fn main() {
    run();
}
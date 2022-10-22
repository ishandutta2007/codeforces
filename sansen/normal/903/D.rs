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
        a: [i128; n],
    }
    let mut z = vec![];
    for a in a.iter() {
        for b in (a - 1)..=(a + 1) {
            z.push(b);
        }
    }
    z.sort();
    z.dedup();
    let mut sum = 0i128;
    let mut ans = 0i128;
    let mut cnt = vec![0i128; z.len()];
    for (i, &a) in a.iter().rev().enumerate() {
        let mut k = i as i128;
        let x = z.binary_search(&a).unwrap();
        let mut s = sum;
        for x in (x - 1)..=(x + 1) {
            s -= cnt[x] * z[x];
            k -= cnt[x];
        }
        ans += s - k * a;
        sum += a;
        cnt[x] += 1;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
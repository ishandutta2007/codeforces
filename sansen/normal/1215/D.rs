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
        s: chars,
    }
    let m = n / 2;
    let mut sum = [0, 0];
    let mut cnt = [0, 0];
    for i in 0..m {
        if s[i] == '?' {
            cnt[0] += 1;
        } else {
            sum[0] += s[i].to_digit(36).unwrap();
        }
    }
    for i in m..n {
        if s[i] == '?' {
            cnt[1] += 1;
        } else {
            sum[1] += s[i].to_digit(36).unwrap();
        }
    }
    if sum[0] < sum[1] {
        sum.swap(0, 1);
        cnt.swap(0, 1);
    }
    if sum[0] == sum[1] {
        if cnt[0] == cnt[1] {
            println!("Bicarp");
        } else {
            println!("Monocarp");
        }
        return;
    }
    if cnt[0] >= cnt[1] {
        println!("Monocarp");
        return;
    }
    let k = cnt[1] - cnt[0];
    let d = sum[0] - sum[1];
    if k / 2 * 9 != d {
        println!("Monocarp");
    } else {
        println!("Bicarp");
    }
}

fn main() {
    run();
}
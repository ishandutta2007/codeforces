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
        m: usize,
        a: [usize; n],
    }
    let mut cnt = vec![0; m + 1];
    for a in a.iter() {
        if *a <= m {
            cnt[*a] += 1;
        }
    }
    for i in (1..=m).rev() {
        let v = cnt[i];
        let mut j = 2 * i;
        while j <= m {
            cnt[j] += v;
            j += i;
        }
    }
    let mut lcm = 1;
    let mut len = 0;
    for i in 1..=m {
        if len < cnt[i] {
            lcm = i;
            len = cnt[i];
        }
    }
    let mut ans = String::new();
    ans.push_str(&format!("{} {}\n", lcm, len));
    for (i, a) in a.iter().enumerate() {
        if lcm % *a == 0 {
            ans.push_str(&format!("{} ", i + 1));
        }
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
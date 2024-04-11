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
        a: [usize; 4],
    }
    let mut a = a;
    a.push(0);
    a.reverse();
    a.push(0);
    a.reverse();
    for s in 1..=4 {
        let mut now = s;
        let mut a = a.clone();
        let mut ans = vec![];
        while a[now] > 0 {
            ans.push(now);
            a[now] -= 1;
            if now - 1 == 1 && a[now - 1] > 0 {
                now -= 1;
            } else if now + 1 == 4 && a[now + 1] > 0 {
                now += 1;
            } else if a[now + 1] > a[now - 1] {
                now += 1;
            } else {
                now -= 1;
            }
        }
        if a.iter().all(|b| *b == 0) {
            let mut out = String::new();
            out.push_str("YES\n");
            for a in ans {
                out.push_str(&format!("{} ", a - 1));
            }
            out.pop();
            println!("{}", out);
            return;
        }
    }
    println!("NO");
}

fn main() {
    run();
}
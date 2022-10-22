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

// 00, 11 0, 1or
// 0
// 01, 10 ?
// zero * one 01, 10 
// 
// 
// 

fn run() {
    input! {
        a: [usize; 4],
    }
    let cond = |b: bool| {
        if !b {
            println!("Impossible");
            std::process::exit(0);
        }
    };
    let mut cnt = [0; 2];
    for (c, a) in cnt.iter_mut().zip([a[0], a[3]].iter()) {
        let mut x = 1;
        while (x + 1) * x / 2 <= *a {
            x += 1;
        }
        cond(x * (x - 1) / 2 == *a);
        *c = x;
    }
    if a[0] > 0 && a[3] > 0 {
        cond(cnt[0] * cnt[1] == a[1] + a[2]);
        let mut ans = vec![];
        let mut a = a;
        while cnt[0] > 0 && cnt[1] > 0 {
            if a[2] >= cnt[1] {
                ans.push(0);
                a[2] -= cnt[1];
                cnt[0] -= 1;
            } else if a[1] >= cnt[0] {
                ans.push(1);
                a[1] -= cnt[0];
                cnt[1] -= 1;
            } else {
                cond(false)
            }
        }
        for (i, c) in cnt.iter_mut().enumerate() {
            for _ in 0..*c {
                ans.push(i);
            }
        }
        ans.reverse();
        let mut s = String::new();
        for a in ans {
            s.push_str(&a.to_string());
        }
        println!("{}", s);
        return;
    } else if a[0] + a[3] > 0 {
        let x = if a[3] > 0 { 1 } else { 0 };
        let c = cnt[x];
        for y in 0..2 {
            if c * y != a[1] + a[2] {
                continue;
            }
            let mut ans = vec![x; c];
            if y > 0 {
                let s = if x == 0 { a[1] } else { a[2] };
                ans.insert(s, x ^ 1);
            }
            let mut s = String::new();
            for a in ans {
                s.push_str(&a.to_string());
            }
            println!("{}", s);
            return;
        }
    } else if a[1] == 1 && a[2] == 0 {
        println!("01");
        return;
    } else if a[2] == 1 && a[1] == 0 {
        println!("10");
        return;
    } else if a.iter().all(|a| *a == 0) {
        println!("0");
        return;
    }
    cond(false);
}

fn main() {
    run();
}
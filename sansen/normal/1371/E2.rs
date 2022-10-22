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
        p: i64,
        a: [i64; n],
    }
    let mut a = a;
    a.sort();
    let mut s = 0;
    for (i, a) in a.iter().enumerate() {
        s = std::cmp::max(s, *a - i as i64);
    }
    let mut cnt = 0;
    let mut r = 0;
    let mut v = 0;
    for j in 0..n {
        while r < n && a[r] <= s + j as i64 {
            cnt += 1;
            r += 1;
        }
        assert!(cnt > 0);
        v = std::cmp::max(v, cnt);
        cnt -= 1;
    }
    if v >= p {
        println!("0");
        return;
    }
    let mut ok = s;
    let mut ng = s + 2 * n as i64;
    while ng - ok > 1 {
        let mid = (ok + ng) / 2;
        let mut cnt = 0;
        let mut r = 0;
        let mut valid = true;
        for j in 0..n {
            while r < n && a[r] <= mid + j as i64 {
                cnt += 1;
                r += 1;
            }
            if cnt >= p {
                valid = false;
                break;
            }
            cnt -= 1;
        }
        if valid {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    let mut ans = vec![];
    for v in s..ng {
        ans.push(v);
    }
    let mut s = String::new();
    s.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        s.push_str(&format!("{} ", a));
    }
    s.pop();
    println!("{}", s);
}

fn main() {
    run();
}
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
        _n: usize,
        s: bytes,
    }
    let s = s.into_iter().map(|c| c == b'1').collect::<Vec<_>>();
    let mut ans = 0u64;
    let mut stack: Vec<(u64, u64)> = vec![];
    let mut sum = 0u64;
    let mut now = 0u64;
    for c in s {
        if c {
            now += 1;
            let mut cnt = 0;
            while stack.last().map_or(false, |p| p.0 <= now) {
                let (h, c) = stack.pop().unwrap();
                sum -= h * c;
                cnt += c;
            }
            if cnt > 0 {
                stack.push((now, cnt));
                sum += now * cnt;
            }
        } else {
            while now > 0 {
                stack.push((now, 1));
                sum += now;
                now -= 1;
            }
            stack.push((0, 1));
            now = 0;
        }
        ans += sum + now * (now + 1) / 2;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
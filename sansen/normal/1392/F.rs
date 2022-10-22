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
        h: [u64; n],
    }
    let mut a = h.clone();
    a.push(0);
    for (a, h) in a.iter_mut().skip(1).zip(h.windows(2)) {
        *a = h[1] - h[0];
    }
    let mut h = a;
    let mut stack: Vec<usize> = vec![];
    for i in 1..n {
        while h[i] > 1 && !stack.is_empty() {
            let x = stack.pop().unwrap();
            let d = (i - x) as u64;
            h[x] = 1;
            if d + 1 <= h[i] {
                h[i] -= d + 1;
                h[i + 1] += d;
            } else {
                let k = h[i] - 1;
                h[i] -= k;
                h[i + 1] += k;
                stack.push(x + (k as usize));
                h[x + (k as usize)] = 0;
            }
        }
        if h[i] > 1 {
            let d = (i + 1) as u64;
            let q = h[i] / d;
            h[0] += q;
            h[i] -= q * d;
            h[i + 1] += q * (d - 1);
        }
        if h[i] > 1 {
            h[0] += 1;
            let d = h[i] - 1;
            h[i] = 1;
            h[i + 1] += d;
            h[d as usize] = 0;
            stack.push(d as usize);
        }
        if h[i] == 0 {
            stack.push(i);
        }
    }
    let mut ans = String::new();
    let mut sum = 0;
    for &h in h.iter().take(n) {
        sum += h;
        ans.push_str(&format!("{} ", sum));
    }
    ans.pop();
    println!("{}", ans);
}

fn main() {
    run();
}
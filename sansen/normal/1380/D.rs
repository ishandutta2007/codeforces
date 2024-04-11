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
        m: usize,
        x: u64,
        k: u64,
        y: u64,
        a: [i32; n],
        b: [i32; m],
    }
    let mut a = a;
    let mut b = b;
    a.insert(0, 0);
    b.insert(0, 0);
    a.push(0);
    b.push(0);
    let mut i = 0;
    let mut ans = 0;
    for b in b.windows(2) {
        assert!(a[i] == b[0]);
        let l = i;
        i += 1;
        while i < a.len() && a[i] != b[1] {
            i += 1;
        }
        if i >= a.len() {
            println!("-1");
            return;
        }
        let r = i;
        let d = (r - l - 1) as u64;
        let mut elem = false;
        for j in (l + 1)..r {
            elem |= a[j] > std::cmp::max(a[l], a[r]);
        }
        if elem && d < k {
            println!("-1");
            return;
        }
        let q = elem as u64;
        let r = (d - q * k) % k;
        let f = (d - q * k - r) / k;
        ans += y * r + x * q + f * std::cmp::min(k * y, x);
    }
    println!("{}", ans);
}

fn main() {
    run();
}
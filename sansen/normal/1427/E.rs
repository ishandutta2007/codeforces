fn rand_memory() -> usize {
    Box::into_raw(Box::new("I hope this is a random number")) as usize
}

fn rand() -> usize {
    static mut X: usize = 0;
    unsafe {
        if X == 0 {
            X = rand_memory();
        }
        X ^= X << 13;
        X ^= X >> 17;
        X ^= X << 5;
        X
    }
}
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

use std::io::Write;

fn run() {
    input! {
        n: u64,
    }
    let mut base = n;
    let mut ans = vec![];
    ans.push((n, '^', n));
    loop {
        assert!(base > 0);
        if base <= 1 {
            break;
        }
        loop {
            let mut tmp = vec![];
            let mut m = rand() % (1 << 20);
            let mut s = base;
            let mut t = 0;
            while m > 0 {
                if m & 1 == 1 {
                    tmp.push((s, '+', t));
                    t += s;
                }
                tmp.push((s, '+', s));
                s += s;
                m >>= 1;
            }
            let mut x = base;
            while t > 0 && t != x {
                if t < x {
                    std::mem::swap(&mut t, &mut x);
                }
                let mut j = 30;
                while t <= (t ^ (x << j)) {
                    j -= 1;
                }
                let mut p = x;
                for _ in 0..j {
                    tmp.push((p, '+', p));
                    p += p;
                }
                tmp.push((t, '^', p));
                t ^= p;
            }
            if x < base {
                ans.append(&mut tmp);
                base = x;
                break;
            }
        }
    }
    println!("{}", ans.len());
    for (a, b, c) in ans {
        println!("{} {} {}", a, b, c);
    }
}

fn main() {
    run();
}
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
    let mut s = s;
    let mut cnt = [0; 3];
    for c in s.iter() {
        let k: usize = c.to_digit(10).unwrap() as usize;
        cnt[k] += 1;
    }
    let m = n / 3;
    if cnt[0] > m {
        for c in s.iter_mut().rev() {
            if *c == '0' && cnt[0] > m {
                cnt[0] -= 1;
                *c = '$';
            }
        }
    }
    if cnt[2] > m {
        for c in s.iter_mut() {
            if *c == '2' && cnt[2] > m {
                cnt[2] -= 1;
                *c = '$';
            }
        }
    }
    for c in s.iter_mut() {
        match *c {
            '1' => {
                if cnt[1] > m && cnt[0] < m {
                    cnt[1] -= 1;
                    cnt[0] += 1;
                    *c = '0';
                }
            },
            '$' => {
                if cnt[0] < m {
                    *c = '0';
                    cnt[0] += 1;
                } else if cnt[1] < m {
                    *c = '1';
                    cnt[1] += 1;
                } else {
                    *c = '2';
                    cnt[2] += 1;
                }
            },
            _ => (),
        }
    }
    for c in s.iter_mut().rev() {
        if *c == '1' && cnt[1] > m {
            cnt[1] -= 1;
            *c = '2';
        }
    }
    let mut out = String::new();
    for c in s {
        out.push(c);
    }
    println!("{}", out);
}

fn main() {
    run();
}
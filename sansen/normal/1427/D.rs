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

fn calc(a: &mut [usize], c: &[usize]) {
    let mut l = 0;
    while l < a.len() {
        let mut r = l + 1;
        while r < c.len() && c[r] == c[l] {
            r += 1;
        }
        a[l..r].reverse();
        l = r;
    }
    a.reverse();
}

fn run() {
    input! {
        n: usize,
        a: [usize1; n],
    }
    if n == 1 {
        println!("0");
        return;
    }
    let mut a = a;
    let mut ans = vec![];
    let mut left = a[0] == 0;
    for i in 0..(n - 1) {
        for j in 0..a.len() {
            if a[j] == i {
                if left {
                    if j != i {
                        let mut c = vec![n; n];
                        let mut id = 0;
                        for k in 0..i {
                            c[k] = id;
                            id += 1;
                        }
                        for k in (j + 1)..n {
                            c[k] = id;
                        }
                        calc(&mut a, &c);
                        ans.push(c);
                        left ^= true;
                    }
                } else {
                    if j != n - 1 - i {
                        let mut c = vec![n; n];
                        let mut id = 0;
                        for k in 0..i {
                            c[n - 1 - k] = id;
                            id += 1;
                        }
                        for k in j..(n - i) {
                            c[k] = id;
                        }
                        calc(&mut a, &c);
                        ans.push(c);
                        left ^= true;
                    }
                }
                break;
            }
        }
    }
    if !a.windows(2).all(|a| a[0] < a[1]) {
        ans.push((0..n).collect());
    }
    println!("{}", ans.len());
    for a in ans {
        let mut a = a.iter().map(|a| (*a, 1)).collect::<Vec<_>>();
        a.dedup_by(|a, b| {
            a.0 == b.0 && {
                b.1 += a.1;
                true
            }
        });
        print!("{}", a.len());
        for d in a {
            print!(" {}", d.1);
        }
        println!();
    }
}

fn main() {
    run();
}
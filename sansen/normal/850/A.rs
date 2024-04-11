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
        p: [[i64; 5]; n],
    }
    if n > 100 {
        println!("0");
        return;
    }
    let mut ans = vec![];
    for i in 0..n {
        let mut q = p.clone();
        let p = q.remove(i);
        for q in q.iter_mut() {
            for (q, p) in q.iter_mut().zip(p.iter()) {
                *q -= *p;
            }
        }
        let mut ok = true;
        for (i, a) in q.iter().enumerate() {
            for b in q.iter().take(i) {
                let mut sum = 0;
                for (a, b) in a.iter().zip(b.iter()) {
                    sum += *a * *b;
                }
                if sum > 0 {
                    ok = false;
                }
            }
        }
        if ok {
            ans.push(i + 1);
        }
    }
    println!("{}", ans.len());
    for (i, a) in ans.iter().enumerate() {
        if i > 0 {
            print!(" ");
        }
        print!("{}", a);
    }
    println!();
}

fn main() {
    run();
}
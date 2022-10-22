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

use std::io::Write;


fn run() {
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [i64; n],
    }
    let mut plus = vec![];
    let mut zero = vec![];
    let mut minus = vec![];
    for (i, a) in a.iter().enumerate() {
        if *a == 0 {
            zero.push(i);
        } else if *a > 0 {
            plus.push(i);
        } else {
            minus.push((*a, i));
        }
    }
    while zero.len() > 1 {
        let x = zero.pop().unwrap();
        let y = zero.pop().unwrap();
        writeln!(out, "1 {} {}", y + 1, x + 1).ok();
        zero.push(x);
    }
    minus.sort();
    let mut remove = false;
    if minus.len() % 2 == 1 {
        if zero.len() > 0 {
            let x = minus.pop().unwrap().1;
            let y = zero.pop().unwrap();
            let (x, y) = (std::cmp::max(x, y), std::cmp::min(x, y));
            writeln!(out, "1 {} {}", y + 1, x + 1).ok();
            zero.push(x);
        } else {
            remove = true;
            let x = minus.pop().unwrap().1;
            writeln!(out, "2 {}", x + 1).ok();
        }
    }
    if zero.len() > 0 && !remove && minus.len() + plus.len() > 0 {
        let x = zero.pop().unwrap();
        writeln!(out, "2 {}", x + 1).ok();
    }
    let mut a = vec![];
    a.append(&mut plus);
    a.append(&mut zero);
    for p in minus {
        a.push(p.1);
    }
    a.sort();
    let x = a.pop().unwrap();
    for a in a {
        writeln!(out, "1 {} {}", a + 1, x + 1).ok();
    }
}

fn main() {
    run();
}
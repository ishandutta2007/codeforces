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

use std::io::Write;

fn run() {
    input! {
        n: usize,
        a: [usize; n],
    }
    let no = || {
        println!("-1");
        std::process::exit(0);
    };
    let mut ans = vec![];
    let mut one: Vec<(usize, usize)> = vec![];
    let mut two: Vec<(usize, usize)> = vec![];
    let inf = 1000000;
    let mut row = inf;
    for (i, &a) in a.iter().enumerate().rev() {
        if a == 0 {
        } else if a == 1 {
            let p = (i, row);
            row -= 1;
            ans.push(p);
            one.push(p);
        } else if a == 2 {
            if let Some((_x, y)) = one.pop() {
                ans.push((i, y));
                two.push((i, y));
            } else {
                no();
            }
        } else {
            if let Some((x, _y)) = two.pop() {
                let h = row;
                row -= 1;
                ans.push((i, h));
                ans.push((x, h));
                two.push((i, h));
            } else if let Some((x, _y)) = one.pop() {
                let h = row;
                row -= 1;
                ans.push((i, h));
                ans.push((x, h));
                two.push((i, h));
            } else {
                no();
            }
        }
    }
    for p in ans.iter_mut() {
        p.1 -= row + 1;
        if p.1 >= n {
            no();
        }
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (x, y) in ans {
        writeln!(out, "{} {}", y + 1, x + 1).ok();
    }
}

fn main() {
    run();
}
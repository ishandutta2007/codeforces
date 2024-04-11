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
        a: [u32; n],
    }
    let mut b = a.iter().enumerate().map(|a| (*a.1, a.0)).collect::<Vec<_>>();
    let mut ans = vec![];
    for i in (1..n).rev() {
        let mut c = vec![];
        for j in 0..i {
            if b[i] < b[j] {
                c.push(j);
            }
        }
        c.sort_by_cached_key(|c| b[*c]);
        for c in c {
            ans.push((i, c));
            b.swap(i, c);
        }
    }
    let mut cnt = 0;
    for i in 0..n {
        for j in 0..i {
            if a[j] > a[i] {
                cnt += 1;
            }
        }
    }
    assert!(ans.len() == cnt && b.windows(2).all(|b| b[0] <= b[1]));
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).ok();
    for (a, b) in ans {
        writeln!(out, "{} {}", b + 1, a + 1).ok();
    }
}

fn main() {
    run();
}
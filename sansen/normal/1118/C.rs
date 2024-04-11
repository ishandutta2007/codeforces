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
        a: [usize; n * n],
    }
    let mut four = vec![];
    let mut two = vec![];
    let mut one = vec![];
    for i in 0..n {
        for j in 0..n {
            if n - 1 - i < i || n - 1 - j < j {
                continue;
            }
            match (i == n - 1 - i, j == n - 1 - j) {
                (true, true) => {
                    one.push((i, j));
                },
                (false, false) => {
                    four.push((i, j));
                },
                _ => {
                    two.push((i, j));
                },
            }
        }
    }
    let mut cnt = vec![0; 1000 + 1];
    for a in a.iter() {
        cnt[*a] += 1;
    }
    let mut ans = vec![vec![0; n]; n];
    for (i, mut c) in cnt.iter().cloned().enumerate() {
        while c >= 4 && four.len() > 0 {
            c -= 4;
            let (a, b) = four.pop().unwrap();
            for x in [a, n - 1 - a].iter() {
                for y in [b, n - 1 - b].iter() {
                    ans[*x][*y] = i;
                }
            }
        }
        while c >= 2 && two.len() > 0 {
            c -= 2;
            let (a, b) = two.pop().unwrap();
            for x in [a, n - 1 - a].iter() {
                for y in [b, n - 1 - b].iter() {
                    ans[*x][*y] = i;
                }
            }
        }
        while c > 0 && one.len() > 0 {
            c -= 1;
            let (a, b) = one.pop().unwrap();
            ans[a][b] = i;
        }
        if c > 0 {
            println!("NO");
            return;
        }
    }
    let mut out = String::from("YES\n");
    for a in ans {
        for a in a {
            out.push_str(&format!("{} ", a));
        }
        out.pop();
        out.push('\n');
    }
    print!("{}", out);
}

fn main() {
    run();
}
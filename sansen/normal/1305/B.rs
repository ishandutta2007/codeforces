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
        s: chars,
    }
    let mut s = s;
    let mut ans = vec![];
    loop {
        let mut b = vec![];
        let mut x = 0;
        let mut y = s.len();
        while x < y {
            if s[x] != '(' {
                x += 1;
            } else if s[y - 1] != ')' {
                y -= 1;
            } else {
                s[x] = '*';
                s[y - 1] = '*';
                b.push(x);
                x += 1;
                y -= 1;
                b.push(y);
            }
        }
        if b.len() == 0 {
            break;
        }
        b.sort();
        ans.push(b);
    }
    let mut out = String::new();
    out.push_str(&format!("{}\n", ans.len()));
    for a in ans {
        out.push_str(&format!("{}\n", a.len()));
        for a in a {
            out.push_str(&format!("{} ", a + 1));
        }
        out.pop();
        out.push('\n');
    }
    print!("{}", out);
}

fn main() {
    run();
}
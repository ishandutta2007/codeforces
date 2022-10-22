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
    input! {
        n: usize,
        l: chars,
        r: chars,
    }
    let mut gl = vec![vec![]; 27];
    let mut gr = vec![vec![]; 27];
    for i in 0..n {
        if l[i] == '?' {
            gl[26].push(i + 1);
        } else {
            let k = l[i] as usize - 'a' as usize;
            gl[k].push(i + 1);
        }
        if r[i] == '?' {
            gr[26].push(i + 1);
        } else {
            let k = r[i] as usize - 'a' as usize;
            gr[k].push(i + 1);
        }
    }
    let mut ans = vec![];
    for i in 0..26 {
        let l = &mut gl[i];
        let r = &mut gr[i];
        while !l.is_empty() && !r.is_empty() {
            let x = l.pop().unwrap();
            let y = r.pop().unwrap();
            ans.push((x, y));
        }
    }
    for i in 0..26 {
        {
            let l = &mut gl[i];
            let r = &mut gr[26];
            while !l.is_empty() && !r.is_empty() {
                let x = l.pop().unwrap();
                let y = r.pop().unwrap();
                ans.push((x, y));
            }
        }
        {
            let l = &mut gl[26];
            let r = &mut gr[i];
            while !l.is_empty() && !r.is_empty() {
                let x = l.pop().unwrap();
                let y = r.pop().unwrap();
                ans.push((x, y));
            }
        }
    }
    let l = &mut gl[26];
    let r = &mut gr[26];
    while !l.is_empty() && !r.is_empty() {
        let x = l.pop().unwrap();
        let y = r.pop().unwrap();
        ans.push((x, y));
    }
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    writeln!(out, "{}", ans.len()).unwrap();
    for (x, y) in ans {
        writeln!(out, "{} {}", x, y).unwrap();
    }
}

fn main() {
    run();
}
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
        k: usize,
        n: usize,
        s: [chars; k],
    }
    let mut s = s;
    s.sort();
    s.dedup();
    let mut ini = s.pop().unwrap();
    if s.is_empty() {
        ini.swap(0, 1);
        let ans: String = ini.into_iter().collect();
        println!("{}", ans);
        return;
    }
    let mut ask = vec![];
    let mut diff = vec![];
    for (i, (x, y)) in ini.iter().zip(s[0].iter()).enumerate() {
        if *x != *y {
            diff.push(i);
        }
    }
    if diff.len() > 4 || diff.len() == 1 {
        println!("-1");
        return;
    }
    if diff.len() == 2 {
        let x = diff[0];
        let y = diff[1];
        for i in 0..n {
            if x != i && y != i {
                ask.push((i, x));
                ask.push((i, y));
            }
        }
        ask.push((x, y));
    } else {
        for (i, x) in diff.iter().enumerate() {
            for y in diff.iter().take(i) {
                ask.push((*x, *y));
            }
        }
    }
    let mut cnt = vec![0; 26];
    for c in ini.iter() {
        cnt[c.to_digit(36).unwrap() as usize - 10] += 1;
    }
    let id = cnt.into_iter().any(|c| c >= 2);
    if id {
        'outer: for i in 0..n {
            for j in 0..i {
                if ini[i] == ini[j] {
                    ask.push((i, j));
                    break 'outer;
                }
            }
        }
    }
    for (x, y) in ask {
        ini.swap(x, y);
        let mut ok = true;
        for s in s.iter() {
            let mut d = vec![];
            for (i, (x, y)) in ini.iter().zip(s.iter()).enumerate() {
                if *x != *y {
                    d.push(i);
                }
            }
            if d.len() > 2 || d.len() == 1 {
                ok = false;
                break;
            }
            if d.is_empty() {
                if !id {
                    ok = false;
                    break;
                }
            } else {
                let p = d[0];
                let q = d[1];
                if !(ini[p] == s[q] && s[p] == ini[q]) {
                    ok = false;
                    break;
                }
            }
        }
        if ok {
            let ans: String = ini.into_iter().collect();
            println!("{}", ans);
            return;
        }
        ini.swap(x, y);
    }
    println!("-1");
}

fn main() {
    run();
}
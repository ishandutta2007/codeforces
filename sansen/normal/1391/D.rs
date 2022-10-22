// ---------- begin chmin, chmax ----------
trait ChangeMinMax {
    fn chmin(&mut self, x: Self) -> bool;
    fn chmax(&mut self, x: Self) -> bool;
}

impl<T: PartialOrd> ChangeMinMax for T {
    fn chmin(&mut self, x: Self) -> bool {
        *self > x && {
            *self = x;
            true
        }
    }
    fn chmax(&mut self, x: Self) -> bool {
        *self < x && {
            *self = x;
            true
        }
    }
}
// ---------- end chmin, chmax ----------
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
        h: usize,
        w: usize,
        s: [bytes; h],
    }
    if h >= 4 {
        println!("-1");
        return;
    }
    if h == 1 {
        println!("0");
        return;
    }
    let inf = h * w;
    let mut dp = vec![0; 1 << h];
    for j in 0..w {
        let mut a = vec![];
        for s in s.iter() {
            let b = (s[j] == b'1') as usize;
            a.push(b);
        }
        let mut next = vec![inf; 1 << h];
        for (i, &v) in dp.iter().enumerate() {
            for (j, next) in next.iter_mut().enumerate(){
                let mut ok = true;
                for k in 0..(h - 1) {
                    let cnt = ((i >> k) & 3).count_ones() + ((j >> k) & 3).count_ones();
                    ok &= cnt % 2 == 1;
                }
                if ok {
                    let mut val = v;
                    for (x, c) in a.iter().enumerate() {
                        if *c != (j >> x) & 1 {
                            val += 1;
                        }
                    }
                    next.chmin(val);
                }
            }
        }
        dp = next;
    }
    let ans = dp.into_iter().min().unwrap();
    println!("{}", ans);
}

fn main() {
    run();
}
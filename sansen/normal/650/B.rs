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
        n: usize,
        a: u64,
        b: u64,
        t: u64,
        s: chars,
    }
    let mut x = vec![1; n];
    for (x, c) in x.iter_mut().zip(s.iter()) {
        if *c == 'w' {
            *x += b;
        }
    }
    let mut ans = 0;
    for _ in 0..2 {
        let mut stack = vec![x[0]];
        for &x in x.iter().skip(1) {
            let v = *stack.last().unwrap() + a + x;
            stack.push(v);
        }
        while stack.last().map_or(false, |p| *p > t) {
            stack.pop();
        }
        ans.chmax(stack.len());
        let mut sum = 0;
        for (i, x) in x.iter().enumerate().rev() {
            sum += x + 2 * a;
            if sum > t {
                break;
            }
            while stack.len() + (n - i) > n || stack.last().cloned().unwrap_or(0) + sum > t {
                stack.pop();
            }
            if stack.is_empty() {
                break;
            }
            ans.chmax(n - i + stack.len());
        }
        x[1..].reverse();
    }
    println!("{}", ans);
}

fn main() {
    run();
}
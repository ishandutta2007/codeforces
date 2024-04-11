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

fn run() {
    input! {
        n: usize,
        x: usize,
        a: [usize; n],
    }
    let mut index = vec![(n + 1, 0, true); x + 2];
    for (i, &a) in a.iter().enumerate() {
        index[a].0.chmin(i + 1);
        index[a].1.chmax(i + 1);
    }
    let mut left = index.clone();
    for i in 1..=x {
        left[i].2 &= left[i - 1].2 && left[i].0 >= left[i - 1].1;
        left[i].0 = std::cmp::min(left[i - 1].0, left[i].0);
        left[i].1 = std::cmp::max(left[i - 1].1, left[i].1);
//        println!("left {}: {} {} {}", i, left[i].0, left[i].1, left[i].2);
    }
    let mut right = index.clone();
    for i in (1..=x).rev() {
        right[i].2 &= right[i + 1].2 && right[i].1 <= right[i + 1].0;
        right[i].0 = std::cmp::min(right[i + 1].0, right[i].0);
        right[i].1 = std::cmp::max(right[i + 1].1, right[i].1);
//        println!("right {}: {} {} {}", i, right[i].0, right[i].1, right[i].2);
    }
    let mut p = 1;
    let mut ans = 0;
    for l in 1..=x {
        if !left[l - 1].2 {
            break;
        }
        p.chmax(l);
        while !right[p + 1].2 || left[l - 1].1 > right[p + 1].0 {
            p += 1;
        }

        ans += (x + 1 - p) as u64;
    }
    println!("{}", ans);
}

fn main() {
    run();
}
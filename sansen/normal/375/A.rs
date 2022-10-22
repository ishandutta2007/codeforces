// ---------- begin next_permutation ----------
fn next_permutation<T: Ord>(a: &mut [T]) -> bool {
    a.windows(2).rposition(|a| a[0] < a[1]).map_or(false, |x| {
        let y = a.iter().rposition(|b| a[x] < *b).unwrap();
        a.swap(x, y);
        a[(x + 1)..].reverse();
        true
    })
}
// ---------- end next_permutation ----------
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

fn run() {
    input! {
        s: bytes,
    }
    let mut cnt = [0; 10];
    for c in s.iter() {
        cnt[(*c - b'0') as usize] += 1;
    }
    let mut a = [1, 6, 8, 9];
    let mut elem = vec![[0; 4]; 7];
    while {
        let val = a.iter().fold(0, |s, a| (10 * s + *a) % 7);
        elem[val] = a;
        next_permutation(&mut a)
    } {}
    let mut ans = String::new();
    cnt[1] -= 1;
    cnt[6] -= 1;
    cnt[8] -= 1;
    cnt[9] -= 1;
    if cnt[1..].iter().any(|c| *c != 0) {
        let mut rem = 0;
        for (i, c) in cnt.iter().enumerate().rev() {
            for _ in 0..(*c) {
                ans.push((b'0' + i as u8) as char);
                rem = (10 * rem + i) % 7;
            }
        }
        rem = 10000 * rem % 7;
        let x = (7 - rem) % 7;
        for &v in elem[x].iter() {
            ans.push((b'0' + v as u8) as char);
        }
    } else {
        ans.push_str("1869");
        for _ in 0..cnt[0] {
            ans.push('0');
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
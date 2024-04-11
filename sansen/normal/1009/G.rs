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

fn valid(cnt: &[usize], mask_cnt: &[usize]) -> bool {
    let mut sum = vec![0];
    for c in cnt.iter() {
        let mut next = sum.clone();
        for s in sum.iter() {
            next.push(*s + *c);
        }
        sum = next;
    }
    let s: usize = mask_cnt.iter().sum();
    let mut a = Vec::with_capacity(mask_cnt.len());
    a.extend_from_slice(mask_cnt);
    for i in 0..cnt.len() {
        for j in 0..mask_cnt.len() {
            if j >> i & 1 == 1 {
                a[j] += a[j ^ (1 << i)];
            }
        }
    }
    for i in 0usize..mask_cnt.len() {
        let x = s - a[((1usize << cnt.len()) - 1) ^ i];
        let y = sum[i];
        if x < y {
            return false;
        }
    }
    true
}

fn run() {
    input! {
        s: chars,
        q: usize,
        cond: [(usize1, chars); q],
    }
    let n = s.len();
    let f = 6;
    let mut mask = vec![(1 << f) - 1; n];
    for (p, s) in cond {
        let mut bit = 0;
        for c in s {
            bit |= 1usize << (c.to_digit(36).unwrap() as usize - 10);
        }
        mask[p] = bit;
    }
    let mut cnt = vec![0; f];
    for c in s.iter() {
        cnt[c.to_digit(36).unwrap() as usize - 10] += 1;
    }
    let mut mask_cnt = vec![0; 1 << f];
    for p in mask.iter() {
        mask_cnt[*p] += 1;
    }
    if !valid(&cnt, &mask_cnt) {
        println!("Impossible");
        return;
    }
    let mut ans = String::new();
    let op: Vec<_> = "abcdef".chars().collect();
    for p in mask {
        mask_cnt[p] -= 1;
        for x in 0..f {
            if (p >> x) & 1 == 1 && cnt[x] > 0 {
                cnt[x] -= 1;
                if valid(&cnt, &mask_cnt) {
                    ans.push(op[x]);
                    break;
                } else {
                    cnt[x] += 1;
                }
            }
        }
    }
    println!("{}", ans);
}

fn main() {
    run();
}
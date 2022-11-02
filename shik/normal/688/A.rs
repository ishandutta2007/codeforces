use std::io;

fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

macro_rules! R {
    ( $ty:ty, ... ) => {
        gets().split_whitespace().map(|x| x.parse::<$ty>().unwrap())
    };
    ( $($ty:ty),* ) => {{
        let line = gets();
        let mut it = line.split_whitespace();
        ( $(it.next().unwrap().parse::<$ty>().unwrap(),)* )
    }}
}

macro_rules! W {
    ( $x:expr ) => {
        println!("{}", $x);
    };
    ( $head:expr, $($tail:expr),* ) => {
        print!("{} ", $head);
        W!($($tail),*);
    }
}

fn main() {
    let (_, d) = R!(i32, i32);
    let mut ans = 0;
    let mut c = 0;
    for _ in 0..d {
        if gets().chars().any(|c| c == '0') {
            c += 1;
        } else {
            c = 0;
        }
        if c > ans {
            ans = c;
        }
    }
    W!(ans);
}
// {{{ by shik

use std::io;

fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

macro_rules! R {
    ( $ty:ty, ... ) => {
        gets().split_whitespace().map(|x| x.parse::<$ty>().unwrap()).collect::<Vec<_>>()
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

// }}}

fn main() {
    let (n,) = R!(usize);
    let mut a: Vec<_> = R!(i32, ...);
    loop {
        let mut done = true;
        for i in 0..n-1 {
            if a[i] > a[i + 1] {
                done = false;
                a.swap(i, i + 1);
                W!(i + 1, i + 2);
            }
        }
        if done { break; }
    }
}
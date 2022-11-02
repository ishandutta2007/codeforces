// {{{ by shik

use std::io;

#[allow(dead_code)]
fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

#[allow(unused_macros)]
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

#[allow(unused_macros)]
macro_rules! W {
    ( $x:expr ) => {{
        println!("{}", $x);
    }};
    ( $x:expr, $($xs:expr),* ) => {{
        print!("{} ", $x);
        W!($($xs),*);
    }}
}

macro_rules! join {
    ($x:expr, $($xs:expr),*; $sep:expr) => { concat!($x, $($sep, $xs),*) }
}

macro_rules! dump {
    ($($x:expr),*) => {
        eprintln!(join!($(concat!(stringify!($x), " = {:?}")),*; ", "), $($x),*);
    }
}

// }}}

fn main() {
    let mut a = [true; 1440 * 2];
    let (n, ) = R!(i32);
    for _ in 0..n {
        let s = gets();
        let h: i32 = s[0..2].parse().unwrap();
        let m: i32 = s[3..5].parse().unwrap();
        let t = h * 60 + m;
        a[t as usize] = false;
    }
    for i in 0..1440 {
        a[i + 1440] = a[i]
    }
    let mut c = 0;
    let mut ans = 0;
    for i in 0..2880 {
        if a[i] {
            c += 1;
        } else {
            c = 0;
        }
        if c > ans {
            ans = c;
        }
    }
    let h = ans / 60;
    let m = ans % 60;
    W!(format!("{:02}:{:02}", h, m));
}
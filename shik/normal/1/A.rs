use std::io;

fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

macro_rules! scanln {
    ( $($ty:ty),* ) => {{
        let line = gets();
        let mut it = line.split_whitespace();
        ( $(it.next().unwrap().parse::<$ty>().unwrap(),)* )
    }}
}

fn main() {
    let (n, m, a) = scanln!(i64, i64, i64);
    let ans = ((n + a - 1) / a) * ((m + a - 1) / a);
    println!("{}", ans);
}
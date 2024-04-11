use std::io;

fn gets() -> String {
    let mut s = String::new();
    io::stdin().read_line(&mut s).unwrap();
    s.trim().to_string()
}

macro_rules! scanln {
    ( $ty:ty, ... ) => {
        gets().split_whitespace().map(|x| x.parse::<$ty>().unwrap())
    };
    ( $($ty:ty),* ) => {{
        let line = gets();
        let mut it = line.split_whitespace();
        ( $(it.next().unwrap().parse::<$ty>().unwrap(),)* )
    }}
}

fn main() {
    gets();
    let mut c = 0;
    for x in scanln!(i32, ...) {
        c ^= (x % 2) ^ 1;
        println!("{}", 2 - c);
    }
}
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
    let (n,) = scanln!(i32);
    let mut v : Vec<&str> = vec![];
    for i in 1..n+1 {
        v.push("I");
        v.push(if i % 2 == 1 { "hate" } else { "love" });
        v.push(if i == n { "it" } else { "that" });
    }
    println!("{}", v.join(" "));
}
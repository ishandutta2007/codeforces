use std::io;
use std::str::FromStr;
use std::fmt::Debug;

struct Reader { row: String }
#[allow(dead_code)] impl Reader {
    fn new() -> Reader { Reader { row: "".to_string() } }
    fn get_next_line(&mut self) -> &str {
        self.row.clear();
        io::stdin().read_line(&mut self.row).ok().unwrap();
        return &self.row;
    }
    fn var<T: FromStr>(&mut self) -> T where T::Err: Debug {
        return self.get_next_line().trim().parse().unwrap();
    }
    fn arr<T: FromStr>(&mut self) -> Vec<T> where T::Err: Debug {
        return self.get_next_line().split_whitespace().map(|s| s.parse().unwrap()).collect();
    }
    fn bytes(&mut self) -> &[u8] { return self.get_next_line().trim().as_bytes(); }
    fn i(&mut self) -> i32 { return self.var(); }
    fn u(&mut self) -> usize { return self.var(); }
    fn arr_i(&mut self) -> Vec<i32> { return self.arr(); }
    fn arr_u(&mut self) -> Vec<usize> { return self.arr(); }
    fn arr_l(&mut self) -> Vec<i64> { return self.arr(); }
    fn u2(&mut self) -> (usize, usize) { let a = self.arr_u(); (a[0], a[1]) }
}

fn is_prime(x: usize) -> bool {
    let mut i = 2;
    while i * i <= x {
        if x % i == 0 { return false; }
        i += 1;
    }
    return true;
}

fn solve(reader: &mut Reader) {
    let (n, mut m) = reader.u2();
    if n == 2 { println!("2 2\n1 2 2"); return; }
    let mut lst = 1;
    while !is_prime(n - 1 + lst) { lst += 1; }
    println!("2 {}", n - 1 + lst);
    println!("1 {} 2", n);
    println!("1 2 {}", lst);
    for i in 3..n { println!("{} {} 1", i - 1, i) };
    m -= n - 1;
    lst += 1;
    if m > 0 { println!("{} {} {}", n - 1, n, lst); m -= 1; };
    for dif in 2..n {
        if m == 0 { break }
        for v1 in 1..n {
            let v2 = v1 + dif;
            if v2 > n || m == 0 { break; }
            m -= 1;
            println!("{} {} {}", v1, v2, lst);
        }
    }
}

fn main() {
    let mut reader = Reader::new();
    solve(&mut reader);
    // let t = reader.u();
    // for _ in 0..t { solve(&mut reader) }
}
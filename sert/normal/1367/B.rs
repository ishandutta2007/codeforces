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
    fn bytes(&mut self) -> &[u8] { return self.get_next_line().as_bytes(); }
    fn i(&mut self) -> i32 { return self.var(); }
    fn u(&mut self) -> usize { return self.var(); }
    fn arr_i(&mut self) -> Vec<i32> { return self.arr(); }
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let (n, a) = (reader.u(), reader.arr_i());
    let odd = a.iter().filter(|&x| x % 2 == 1).count();
    let mis = (0..n).filter(|&x| x % 2 != (a[x] % 2) as usize).count();
    println!("{}", if n / 2 == odd { (mis / 2) as i32 } else { -1 });
}

fn main() {
    let mut reader = Reader::new();
    let t = reader.i();
    for _ in 0..t { solve(&mut reader) }
}
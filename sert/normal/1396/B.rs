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
    fn arr_l(&mut self) -> Vec<i64> { return self.arr(); }
}

fn solve(reader: &mut Reader) {
    let (_, arr) = (reader.u(), reader.arr_i());
    let sum: i32 = arr.iter().sum();
    let mx: i32 = *arr.iter().max().unwrap();
    if sum % 2 == 1 || mx > sum - mx {
        println!("T");
    } else {
        println!("HL");
    }
}

fn main() {
    let mut reader = Reader::new();
    let t = reader.u();
    for _ in 0..t { solve(&mut reader) }
}
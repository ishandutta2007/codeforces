use std::io;
use std::str::FromStr;
use std::fmt::Debug;

struct Reader { row: String }
#[allow(dead_code)] impl Reader {
    fn new() -> Reader { Reader { row: "".to_string() } }
    fn get_next_line(&mut self) -> &str {
        self.row.clear();
        io::stdin().read_line(&mut self.row).ok().expect("");
        return &self.row;
    }
    fn var<T: FromStr>(&mut self) -> T where T::Err: Debug {
        return self.get_next_line().trim().parse().unwrap();
    }
    fn arr<T: FromStr>(&mut self) -> Vec<T> where T::Err: Debug {
        return self.get_next_line().split_whitespace().map(|s| s.parse().expect("")).collect();
    }
    fn str(&mut self) -> &str { return self.get_next_line(); }
}

fn main() {
    let mut reader = Reader::new();
    let n: i32 = reader.var();
    for _ in 0..n {
        let s = reader.str().as_bytes();
        print!("{}", s[0] as char);
        for ind in (1..s.len()).step_by(2) {
            print!("{}", s[ind] as char);
        }
        println!();
    }
}
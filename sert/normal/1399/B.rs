use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;


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
    fn bytes(&mut self) -> &[u8] { return self.get_next_line().as_bytes(); }
    fn i(&mut self) -> i32 { return self.var(); }
    fn arr_i(&mut self) -> Vec<i32> { return self.arr(); }
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let n = reader.i() as usize;
    let (a, b) = (reader.arr_i(), reader.arr_i());
    let min_a: &i32 = a.iter().min().expect("");
    let min_b: &i32 = b.iter().min().expect("");
    let v: Vec<(i32, i32)> = (0..n).map(|x| (a[x], b[x])).collect();
    let ans: i64 = v.iter().map(|(a, b)| max(a - min_a, b - min_b) as i64).sum();
    println!("{}", ans);
}

fn main() {
    let mut reader = Reader::new();
    let t = reader.i();
    for _ in 0..t { solve(&mut reader) }
}
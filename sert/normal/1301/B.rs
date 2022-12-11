use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::cmp::max;

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
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let (n, a) = (reader.u(), reader.arr_i());
    let mut ans = (1..n).map(|i| if a[i] == -1 || a[i - 1] == -1 {0} else {(a[i] - a[i - 1]).abs()}).max().unwrap();
    let v: Vec<i32> = ((1..n).filter(|&i| (a[i] == -1) != (a[i - 1] == -1)).map(|i| a[i - 1] + a[i] + 1)).collect();
    if v.is_empty() { println!("{} 34", ans); return; }
    let mn = v.iter().min().unwrap();
    let mx = v.iter().max().unwrap();
    let mid = mn + (mx - mn) / 2;
    ans = max(ans, mx - mid);
    println!("{} {}", ans, mid);
}

fn main() {
    let mut reader = Reader::new();
    // solve(&mut reader);
    let t = reader.u();
    for _ in 0..t { solve(&mut reader) }
}
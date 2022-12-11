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
    fn i2(&mut self) -> (i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1]); }
    fn i3(&mut self) -> (i32, i32, i32) { let arr = self.arr_i(); return (arr[0], arr[1], arr[2]); }
}

fn solve(reader: &mut Reader) {
    let (n, s) = reader.i2();
    let a = reader.arr_i();
    let (mut l, mut r) = (0usize, (n + 1) as usize);
    let mut t = 0i64;
    while r - l > 1 {
        let m = (l + r) / 2;
        let mut v: Vec<i64> = (0..n as usize).map(|x| (x as i64 + 1) * m as i64 + a[x] as i64).collect();
        v.sort();
        let sum: i64 = v.iter().take(m).sum();
        if sum <= s as i64 { l = m; t = sum; } else { r = m; }
    }
    println!("{} {}", l, t);
}

fn main() {
    let mut reader = Reader::new();
    solve(&mut reader);
    // let t = reader.u();
    // for _ in 0..t { solve(&mut reader) }
}
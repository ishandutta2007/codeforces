use std::io;
use std::str::FromStr;
use std::fmt::Debug;
use std::collections::HashSet;

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
    let n = reader.u();
    let mut a: Vec<usize> = reader.arr();
    let mut s: HashSet<usize> = HashSet::new();
    a.iter().for_each(|&x| if x > 0 { s.insert(x - 1); });
    let mut keys = vec![0usize; 0];
    let mut values = vec![0usize; 0];
    (0..n).for_each(|i| if a[i] == 0 && !s.contains(&i) { keys.push(i); values.push(i); });
    (0..n).for_each(|i| if a[i] == 0 && s.contains(&i) { keys.push(i); });
    (0..n).for_each(|i| if a[i] > 0 && !s.contains(&i) { values.push(i); });
    values.rotate_right(1);
    (0..keys.len()).for_each(|i| a[keys[i]] = values[i] + 1);
    a.iter().for_each(|x| print!("{} ", x));
    println!();
}

fn main() {
    let mut reader = Reader::new();
    solve(&mut reader);
    // let t = reader.u();
    // for _ in 0..t { solve(&mut reader) }
}
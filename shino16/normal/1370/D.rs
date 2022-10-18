fn main() {
    let v = read_vec::<usize>();
    let (n, k) = (v[0], v[1]);
    let a = read_vec::<i64>();
 
    let criterion1 = |mid| {
        let mut pointer = 0;
        let mut count = 0;
        while pointer < n - (if k % 2 == 0 { 1 } else { 0 }) {
            if a[pointer] <= mid {
                count += 1;
                pointer += 1;
            }
            pointer += 1;
        }
        count < (k + 1) / 2
    };
    let criterion2 = |mid| {
        let mut pointer = 1;
        let mut count = 0;
        while pointer < n - (if k % 2 == 0 { 0 } else { 1 }) {
            if a[pointer] <= mid {
                count += 1;
                pointer += 1;
            }
            pointer += 1;
        }
        count < k / 2
    };
 
    let search_max = a.iter().max().unwrap() + 1;
    let (_, ans) = binary_search(0, search_max, criterion1, criterion2);
    println!("{}", ans);
}
 
fn binary_search<F1, F2>(lb: i64, ub: i64, criterion1: F1, criterion2: F2) -> (i64, i64)
where
    F1: Fn(i64) -> bool,
    F2: Fn(i64) -> bool,
{
    let mut ok = lb;
    let mut ng = ub;
    while ng - ok > 1 {
        let mid = (ng + ok) / 2;
        if criterion1(mid) && criterion2(mid) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    (ok, ng)
}
 
fn read<T: std::str::FromStr>() -> T {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).ok();
    s.trim().parse().ok().unwrap()
}
 
fn read_vec<T: std::str::FromStr>() -> Vec<T> {
    read::<String>()
        .split_whitespace()
        .map(|e| e.parse().ok().unwrap())
        .collect()
}
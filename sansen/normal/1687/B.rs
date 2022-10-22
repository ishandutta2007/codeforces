// 
// 
//
// N <= 200
// M <= 500
// 2m
//
// 
// 
// 
// 

use std::io::Write;
use std::collections::*;

type Map<K, V> = BTreeMap<K, V>;
type Set<T> = BTreeSet<T>;
type Deque<T> = VecDeque<T>;

fn read() -> Vec<u32> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    use util::*;
    let (n, m) = {
        let a = read();
        (a[0] as usize, a[1] as usize)
    };
    let mut cnt = 0;
    let mut query = |s: Vec<char>| -> u32 {
        assert!(s.iter().all(|s| *s == '0' || *s == '1'));
        assert!(cnt < 2 * m);
        cnt += 1;
        use util::*;
        println!("? {}", s.iter().join(""));
        read()[0]
    };
    let mut weight = vec![0; m];
    for i in 0..m {
        let mut s = vec!['0'; m];
        s[i] = '1';
        weight[i] = query(s);
    }
    let mut ord = (0..m).collect::<Vec<_>>();
    ord.sort_by_key(|v| weight[*v]);
    let mut sum = 0;
    let mut state = vec!['0'; m];
    for v in ord {
        let mut s = state.clone();
        s[v] = '1';
        let ans = query(s.clone());
        if ans == sum + weight[v] {
            state = s;
            sum += weight[v];
        }
    }
    println!("! {}", sum);
}

fn main() {
    run();
}

mod util {
    pub trait Join {
        fn join(self, sep: &str) -> String;
    }

    impl<T, I> Join for I
    where
        I: Iterator<Item = T>,
        T: std::fmt::Display,
    {
        fn join(self, sep: &str) -> String {
            let mut s = String::new();
            use std::fmt::*;
            for (i, v) in self.enumerate() {
                if i > 0 {
                    write!(&mut s, "{}", sep).ok();
                }
                write!(&mut s, "{}", v).ok();
            }
            s
        }
    }
}
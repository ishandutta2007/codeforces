// 
// 
// ceil(n / 2) 
//
// d=1
// 1
// n1

fn read() -> Vec<usize> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().split_whitespace().flat_map(|s| s.parse()).collect()
}

fn run() {
    let n = read()[0];
    let mut cnt = 0;
    let mut map = std::collections::BTreeMap::<usize, Vec<usize>>::new();
    let mut query = |root: usize| -> Vec<usize> {
        assert!(root < n);
        if let Some(dp) = map.get(&root) {
            return dp.clone();
        }
        assert!(cnt < (n + 1) / 2);
        cnt += 1;
        println!("? {}", root + 1);
        let dp = read();
        map.insert(root, dp.clone());
        dp
    };
    let d = query(0);
    let mut a = vec![vec![]; 2];
    for (i, d) in d.iter().enumerate() {
        a[*d & 1].push(i);
    }
    let mut p = 0;
    if a[1].len() < a[0].len() {
        p = 1;
    }
    let mut edge = vec![];
    for a in a[p].iter() {
        let dp = query(*a);
        for (i, d) in dp.iter().enumerate() {
            if *d == 1 {
                edge.push((i, *a));
            }
        }
    }
    println!("!");
    for (a, b) in edge {
        println!("{} {}", a + 1, b + 1);
    }
}

fn main() {
    run();
}
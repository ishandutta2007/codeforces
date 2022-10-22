// 
// k_i = 0, n - 1 
// 0 < k_i < n - 1 
// 
// 3DAG 

fn read() -> Vec<String> {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim()
        .split_whitespace()
        .map(|s| String::from(s))
        .collect()
}

fn run() {
    let n = read()[0].parse::<usize>().unwrap();
    let mut k = read()
        .into_iter()
        .enumerate()
        .map(|(i, s)| (s.parse::<usize>().unwrap(), i + 1))
        .collect::<Vec<_>>();
    k.sort();
    let mut query = vec![];
    for i in 1..n {
        if k[i].0 == 0 || k[i].0 == n - 1 {
            continue;
        }
        for j in 0..i {
            if k[j].0 == 0 || k[j].0 == n - 1 {
                continue;
            }
            query.push((k[i].0 - k[j].0, k[i].1, k[j].1));
        }
    }
    query.sort();
    for &(_, x, y) in query.iter().rev() {
        println!("? {} {}", x, y);
        if read()[0] == "Yes" {
            println!("! {} {}", x, y);
            return;
        }
    }
    println!("! 0 0");
}

fn main() {
    run();
}
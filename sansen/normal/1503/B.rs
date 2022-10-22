// 
// 
// 1, 2 
// 3

fn read() -> usize {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn run() {
    let n = read();
    let mut pos = vec![vec![]; 2];
    for i in 1..=n {
        for j in 1..=n {
            pos[(i + j) & 1].push((i, j));
        }
    }
    while pos[0].len() > 0 && pos[1].len() > 0 {
        let a = read();
        if a == 1 {
            let (x, y) = pos[1].pop().unwrap();
            println!("2 {} {}", x, y);
        } else {
            let (x, y) = pos[0].pop().unwrap();
            println!("1 {} {}", x, y);
        }
    }
    for &(x, y) in pos[1].iter() {
        let a = read();
        if a == 2 {
            println!("3 {} {}", x, y);
        } else {
            println!("2 {} {}", x, y);
        }
    }
    for &(x, y) in pos[0].iter() {
        let a = read();
        if a == 1 {
            println!("3 {} {}", x, y);
        } else {
            println!("1 {} {}", x, y);
        }
    }
}

fn main() {
    run();
}
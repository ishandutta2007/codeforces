use std::io::Write;

fn read() -> u32 {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    s.trim().parse().unwrap()
}

fn query(a: usize, b: usize) -> u32 {
    println!("? {} {}", a, b);
    std::io::stdout().flush().ok();
    read()
}

fn gcd(a: u32, b: u32) -> u32 {
    if b == 0 {
        a
    } else {
        gcd(b, a % b)
    }
}

fn run() {
    let v = [4, 8, 15, 16, 23, 42];
    let mut ans = [0u32; 6];
    let mut a = vec![];
    let mut elem = 0;
    for i in 0..4 {
        let v = query(1, i + 2);
        elem += (v % 5 == 0) as usize;
        a.push(v);
    }
    if elem > 1 {
        ans[0] = 15;
    } else if elem == 1 {
        ans[0] = a.iter().fold(0, |s, a| gcd(s, *a));
    } else if a.iter().filter(|a| *a % 7 == 0).count() > 1 {
        ans[0] = 42;
    } else {
        for i in 0..4 {
            if a[i] % 7 == 0 {
                ans[0] = a[i] / 42;
            }
        }
    }
    for i in 0..4 {
        ans[i + 1] = a[i] / ans[0];
    }
    ans[5] = v.iter().product::<u32>() / ans.iter().take(5).product::<u32>();
    let mut s = String::new();
    s.push('!');
    for &a in ans.iter() {
        s.push_str(&format!(" {}", a));
    }
    println!("{}", s);
}

fn main() {
    run();
}
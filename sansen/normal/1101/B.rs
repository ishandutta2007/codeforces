fn solve(s: &mut Vec<char>) -> i32 {
    for v in [']', ':'].iter().cloned() {
        let mut ok = false;
        while let Some(c) = s.pop() {
            if c == v {
                ok = true;
                break;
            }
        }
        if !ok {
            return -1;
        }
    }
    s.reverse();
    for v in ['[', ':'].iter().cloned() {
        let mut ok = false;
        while let Some(c) = s.pop() {
            if c == v {
                ok = true;
                break;
            }
        }
        if !ok {
            return -1;
        }
    }
    let mut ans = 4;
    for c in s.iter().cloned() {
        if c == '|' {
            ans += 1;
        }
    }
    return ans;
}

fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut s: Vec<char> = s.trim().chars().collect();
    let ans = solve(&mut s);
    println!("{}", ans);
}

fn main() {
    run();
}
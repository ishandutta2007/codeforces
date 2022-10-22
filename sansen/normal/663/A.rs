fn run() {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    let mut s: Vec<_> = s.trim().split_whitespace().map(|s| String::from(s)).collect();
    let n: i64 = s.pop().unwrap().parse().unwrap();
    assert!(s.pop().unwrap() == "=");
    s.insert(0, String::from("+"));
    let mut sum = 0i64;
    let mut minus = vec![];
    let mut plus = vec![];
    for (i, s) in s.chunks_exact_mut(2).enumerate() {
        let sign = if s[0] == "+" {1} else {-1};
        if let Ok(v) = s[1].parse::<i64>() {
            sum += v * sign;
        } else if sign == 1 {
            plus.push(i);
            s[1] = String::from("1");
            sum += 1;
        } else {
            minus.push(i);
            s[1] = String::from("1");
            sum -= 1;
        }
    }
    for k in plus.iter() {
        if sum >= n {
            break;
        }
        sum -= 1;
        let v = std::cmp::min(n, n - sum);
        s[2 * k + 1] = format!("{}", v);
        sum += v;
    }
    for k in minus.iter() {
        if sum <= n {
            break;
        }
        sum += 1;
        let v = std::cmp::min(n, sum - n);
        s[2 * k + 1] = format!("{}", v);
        sum -= v;
    }
    if sum != n {
        println!("Impossible");
        return;
    }
    let mut out = String::from("Possible\n");
    for s in s.iter().skip(1) {
        out.push_str(s);
        out.push(' ');
    }
    out.push_str(&format!("= {}", n));
    println!("{}", out);
}

fn main() {
    run();
}
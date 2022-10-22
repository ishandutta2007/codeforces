fn read() -> String {
    let mut s = String::new();
    std::io::stdin().read_line(&mut s).unwrap();
    String::from(s.trim())
}

fn run() {
    let n = 8;
    let mut pos = (1i32, 1i32);
    println!("{} {}", pos.0, pos.1);
    let mut dp = vec![];
    for i in 1..=n {
        for j in 1..=n {
            if (i, j) != (1, 1) {
                dp.push((i, j));
            }
        }
    }
    let mut map = std::collections::BTreeMap::new();
    map.insert("Left", (0, -1));
    map.insert("Right", (0, 1));
    map.insert("Up", (-1, 0));
    map.insert("Down", (1, 0));
    map.insert("Down-Right", (1, 1));
    map.insert("Down-Left", (1, -1));
    map.insert("Up-Left", (-1, -1));
    map.insert("Up-Right", (-1, 1));
    let done = "Done";
    let mut dir = 1;
    let mut res = read();
    for _ in 0..130 {
        if res == done {
            break;
        }
        let (dx, dy) = *map.get(res.as_str()).unwrap();
        dp = dp
            .into_iter()
            .filter(|&(x, y)| {
                let x = x + dx;
                let y = y + dy;
                1 <= x
                    && x <= n
                    && 1 <= y
                    && y <= n
                    && x != pos.0
                    && y != pos.1
                    && (pos.0 - x).abs() != (pos.1 - y).abs()
            })
            .map(|p| (p.0 + dx, p.1 + dy))
            .collect();
        if dp.iter().all(|p| pos.1 + 1 != p.1) {
            pos.1 += 1;
        } else {
            pos.0 += dir;
            if pos.0 == 1 {
                dir = 1;
            }
            if pos.0 == n {
                dir = -1;
            }
        }
        println!("{} {}", pos.0, pos.1);
        res = read();
    }
    if res == done {
        return;
    }
    unreachable!()
}

fn main() {
    let t = read().parse::<usize>().unwrap();
    for _ in 0..t {
        run();
    }
}
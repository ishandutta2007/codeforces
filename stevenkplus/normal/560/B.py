def go():
    a, b = map(int, raw_input().split(" "))
    x, y = map(int, raw_input().split(" "))
    m, n = map(int, raw_input().split(" "))
    for i in range(2):
        for j in range(2):
            if x + m <= a and y + n <= b:
                return "YES"
            if x + m <= a and max(y, n) <= b:
                return "YES"
            if max(x, m) <= a and y + n <= b:
                return "YES"
            m, n = n, m
        y, x = x, y
    return "NO"

print go()
from sys import stdout

n, t = map(int, input().split())
for _ in range(t):
    k = int(input())
    l = 1
    r = n + 1
    while l < r:
        m = (l + r) // 2
        print('?', 1, m)
        stdout.flush()
        ret = m - int(input())
        if ret >= k:
            r = m
        else:
            l = m + 1
    print('!', l)
    stdout.flush()
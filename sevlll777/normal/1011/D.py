from sys import stdout
q, n = map(int, input().split())
P = []
for i in range(n):
    print(1)
    stdout.flush()
    ans = int(input())
    if ans == 0:
        exit(0)
    P.append(ans)
low = 1
high = q + 1
i = 0
while True:
    m = (low + high) // 2
    print(m)
    stdout.flush()
    ans = int(input())
    if ans == 0:
        exit(0)
    if P[i] == ans:
        low = m
    else:
        high = m
    i += 1
    i %= n
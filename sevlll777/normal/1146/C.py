from sys import stdout
from math import log2
for i in range(int(input())):
    n = int(input())
    stdout.flush()
    ans = 0
    q = int(log2(n))
    while q != -1:
        k = 2 ** q
        q1 = []
        q2 = []
        for i in range(n):
            if ((i + 1) // k) % 2:
                q1.append(i + 1)
            else:
                q2.append(i + 1)
        print(len(q1), len(q2), *q1, *q2)
        stdout.flush()
        a = int(input())
        stdout.flush()
        ans = max(ans, a)
        q -= 1
    print(-1, ans)
    stdout.flush()
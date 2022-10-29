#!/usr/bin/env python3

n = input()
ans = max(int(c) for c in n)
print(ans)
vl = len(n)
n = int(n)
for i in range(ans):
    x = 0
    for j in range(vl):
        dig = n % (10 ** (j + 1)) // (10 ** j)
        if dig != 0:
            n -= 10 ** j
            x += 10 ** j
    print(x, end=" ")
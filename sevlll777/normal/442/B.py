n = int(input())
P = list(map(float, input().split()))
if 1 in P:
    print(1)
    exit(0)
Q = []
for i in P:
    Q.append(1 - i)
Q.sort()
ans = 0
c1 = 1
c2 = 0
for i in Q:
    if (c1 * i) * (c2 + 1 / i - 1) > ans:
         ans = (c1 * i) * (c2 + 1 / i - 1)
         c1 *= i
         c2 += (1 / i - 1)
print(ans)
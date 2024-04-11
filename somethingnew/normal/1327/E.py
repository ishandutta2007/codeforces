from time import time
power = [1] * 200002
for i in range(1,200002):
    power[i] = power[i-1] * 10 % 998244353
n = int(input())
if n == 1:
    print(10)
else:
    m = [0] * n
    m[n-1] = 10
    shag = 2
    for i in range(n-2,-1,-1):
        ans = 2 * 10 * (9 * power[shag - 2])
        ans %= 998244353
        ans += 10 * 9 * 9 * power[shag - 3] * (shag - 2)
        m[i] = int(ans % 998244353)
        shag += 1
    print(*m)
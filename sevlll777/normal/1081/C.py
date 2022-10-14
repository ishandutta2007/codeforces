from math import factorial
n, m, k = map(int, input().split())
M = 998244353
fn = 1
fnk1 = 1
fk = 1
for i in range(1, n):
    fn *= i
    fn %= M
for i in range(1, n - k):
    fnk1 *= i
    fnk1 %= M
for i in range(1, k + 1):
    fk *= i
    fk %= M
print((fn * pow((fnk1 * fk), M - 2, M)) * m * pow(m - 1, k, M) % M)
M = 10 ** 9 + 7
m = int(input())
A = list(map(int, input().split()))
D = {}
for i in A:
    if i not in D:
        D[i] = 0
    D[i] += 1
alph = 1
for j in D:
    alph *= (D[j] + 1)
ans = 1
for j in D:
    ans *= pow(j, alph * D[j] // 2 % (M - 1), M)
    ans %= M
print(ans)
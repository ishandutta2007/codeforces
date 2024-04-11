good = [1]
while good[-1] < 10 ** 18:
    good.append(good[-1] * 2 + 1)
def solve():
    n = int(input())
    res = 0
    for i in good:
        if i * (i + 1) // 2 <= n:
            res += 1
            n -= i * (i + 1) // 2
    print(res)
for i in range(int(input())):
    solve()
def dfs(i):
    if i >= 2 ** n:
        return 0, 0
    x1, m1 = dfs(i * 2)
    x2, m2 = dfs(i * 2 + 1)
    if m1 + a[i * 2] < m2 + a[i * 2 + 1]:
        return x1 + x2 + m2 + a[i * 2 + 1] - m1 - a[i * 2], m2 + a[i * 2 + 1]
    return x1 + x2 + m1 + a[i * 2] - m2 - a[i * 2 + 1], m1 + a[i * 2]
n = int(input())
a = [0, 0] + [int(i) for i in input().split()]
print(dfs(1)[0])
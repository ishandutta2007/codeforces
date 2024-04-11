n = int(input())
B = []
ans = [-1] * (2 * n)
used = [0] * (2 * n)
for i in range(1, 2 * n):
    A = list(map(int, input().split()))
    for j in range(i):
        B.append((A[j], i, j))
B.sort(reverse=True)
for gg, i, j in B:
    if used[i] == used[j] == 0:
        ans[i] = j + 1
        ans[j] = i + 1
        used[i] = 1
        used[j] = 1
print(*ans)
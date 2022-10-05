n = int(input())
lst = list(map(int,input().split()))
ans = [-1 for i in range(n)]
lst.sort()
k = n//2
for i in range(k):
    ans[i * 2 + 1] = lst[i]
for i in range(k, n):
    ans[(i - k) * 2] = lst[i]
res = 0
for i in range(1, n-1):
    if ans[i-1] > ans[i] and ans[i] < ans[i + 1]:
        res += 1
print(res)
print(*ans)
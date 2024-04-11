n = int(input())
ans = {}
for i in range(n):
    a, x = map(int, input().split())
    if a not in ans:
        ans[a] = set()
    ans[a].add(x)
m = int(input())
for i in range(m):
    a, x = map(int, input().split())
    if a not in ans:
        ans[a] = set()
    ans[a].add(x)
cnt = 0
for j in ans:
    cnt += max(ans[j])
print(cnt)
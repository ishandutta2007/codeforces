n = int(input())
ans = []
for s in range(1, min(n + 1, 99)):
    x = n - s
    sm = sum(int(i) for i in str(x))
    if sm == s:
        ans.append(x)
print(len(ans))
for i in sorted(ans):
    print(i, end=' ')
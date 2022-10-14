n = int(input())
B = list(map(int, input().split()))
pp = {}
for i in range(n):
    if B[i] - (i + 1) not in pp:
        pp[B[i] - (i + 1)] = 0
    pp[B[i] - (i + 1)] += B[i]
ans = 0
for c in pp:
    ans = max(ans, pp[c])
print(ans)
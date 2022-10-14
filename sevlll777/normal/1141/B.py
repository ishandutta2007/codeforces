n = int(input())
S = list(map(int, input().split()))
S.extend(S)
ans = 0
cnt = 0
for i in S:
    if i:
        cnt += 1
    else:
        ans = max(ans, cnt)
        cnt = 0
print(ans)
s = list(input())
glas = 'AEIOUY'
cnt = 0
ans = 0
for i in s:
    if i not in glas:
        cnt += 1
    else:
        ans = max(ans, cnt)
        cnt = 0
print(max(cnt, ans) + 1)
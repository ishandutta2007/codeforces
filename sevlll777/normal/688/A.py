n, d = map(int, input().split())
cnt = 0
ans = 0
for i in range(d):
    if '0' not in input():
        ans = max(ans, cnt)
        cnt = 0
    else:
        cnt += 1
print(max(ans, cnt))
n, k = map(int, input().split())
s = input().strip()
cnt = dict()
for i in s:
    if i not in cnt:
        cnt[i] = 0
    cnt[i] += 1
a = []
for i in cnt:
    a.append(cnt[i])
a.sort(reverse=True)
cn = 0
ans = 0
for i in range(len(a)):
    if a[i] + cn <= k:
        ans += a[i] * a[i]
        cn += a[i]
    else:
        ans += (k - cn) * (k - cn)
        break
print(ans)
s = raw_input().split()
n = int(s[0])
k = int(s[1])
s = raw_input().split()
a = [int(s[i]) for i in range(0,n)]
ans = dict({})
ans[0] = 0
for i in range(0, n):
    anss = ans.copy()
    for j in ans:
        if not ans.__contains__(j + a[i]):
            anss[j + a[i]] = ans[j] ^ (1 << i)
        if len(anss) > k:
            break
    ans = anss
    if len(ans) > k:
        break
for j in ans:
    if j == 0: continue
    now = 0
    s = ""
    for i in range(0, n):
        if ((1 << i) & ans[j]) != 0:
            s += " " + str(a[i])
            now += 1
    print(str(now) + s)
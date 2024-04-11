def check(mid):
    qa = False
    for i in range(n - mid + 1):
        u = 0
        for j in range(i):
            if u < m and s[j] == t[u]:
                u += 1
        for j in range(i + mid, n):
            if u < m and s[j] == t[u]:
                u += 1
        if u == m:
            qa = True
            break
    return qa


s = input()
t = input()
n = len(s)
m = len(t)
l = -1
r = n - m + 1
while r - l > 1:
    mid = (l + r) // 2
    if check(mid):
        l = mid
    else:
        r = mid
print(l)
n = int(input())
s = list(input())
s = list(map(int, s))
for pref in range(n-1):
    sm = sum(s[:pref+1])
    cnt = 0
    g = 0
    for j in range(pref+1, n):
        cnt += s[j]
        if cnt == sm:
            cnt = 0
            g = 1
    if cnt == 0 and g:
        print('YES')
        exit(0)
print('NO')
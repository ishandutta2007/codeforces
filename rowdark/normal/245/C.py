a = [0 for i in range(0,1001)]
n = int(input())
s = raw_input()
nowpos = 1
for i in s:
    if i.isspace():
        nowpos += 1
    else:
        a[nowpos] = a[nowpos] * 10 + int(i)
if n < 3 or n % 2 == 0:
    print(-1)
else:
    ans = 0
    for i in range(0,n):
        j = n - i
        if a[j] < 0: a[j] = 0
        if j == 1:
            ans += a[j]
        elif j % 2 == 1:
            ans += a[j]
            a[j-1] -= a[j]
            a[j//2] -= a[j]
        else:
            ans += a[j]
            a[j//2] -= a[j]
    print(ans)
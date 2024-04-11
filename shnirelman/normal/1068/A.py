a = input().split()
n = int(a[0])
m = int(a[1])
k = int(a[2])
l = int(a[3])

if k + l > n:
    print(-1)
else:
    ans = (k + l) // m
    if (k + l) % m > 0:
        ans += 1
    if(ans * m > n):
        print(-1)
    else:
        print(ans)
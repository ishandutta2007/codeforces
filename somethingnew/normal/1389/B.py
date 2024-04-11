def solve():
    n, k, z = map(int,input().split())
    lst = list(map(int,input().split()))
    maxsum = 0
    for zz in range(z+1):
        sum = lst[0]
        maxn = lst[0] + lst[1]
        if k-zz * 2 < 0:
            break
        for i in range(k-zz * 2):
            if i + 2 < n:
                maxn = max(maxn, lst[i+1] + lst[i+2])
            sum += lst[i+1]
        sum += maxn * zz
        maxsum = max(maxsum,sum)
    print(maxsum)
for i in range(int(input())):
    solve()
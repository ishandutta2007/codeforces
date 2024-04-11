n = int(input())
a = list(map(int, input().split()))
a.sort()
mn = a[1] - a[0]
for i in range(1, n):
    if(mn > a[i] - a[i - 1]):
        mn = a[i] - a[i - 1]
res = 0
for i in range(1, n):
    if(a[i] - a[i-1] == mn):
        res += 1
print(mn, res)
import sys
input = sys.stdin.readline

n = int(input())
s = [int(x) for x in input().split()]
d = []
s.sort()
for i in range(n - 1):
    d.append(s[i + 1] - s[i])
d.sort()
#print(d)
if(n > 1):
    pre = [d[0]]
    for i in range(n - 2):
        pre.append(pre[i] + d[i + 1])
#print(pre)
q = int(input())
for _ in range(q):
    [l, r] = [int(x) for x in input().split()]
    l, r = 0, r - l
    if(n == 1):
        print(r + 1, end = ' ')
    elif(d[0] > r + 1):
        print((r + 1) * n, end = ' ')
    else:
        lo = 0
        hi = n - 2
        while(lo < hi):
            mi = (lo + hi + 1)//2
            if(d[mi] <= r + 1):
                lo = mi
            else:
                hi = mi - 1
        print(pre[lo] + (r + 1)*(n - lo - 1), end = ' ')
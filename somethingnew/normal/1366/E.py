n, m = map(int,input().split())
lstn = list(map(int,input().split()))
b = list(map(int,input().split()))
hr = [0 for i in range(m)]
hhr = [-1 for i in range(m)]
hhl = [-1 for i in range(m)]
def bnp(lst, elem, pos):
    l = -1
    r = len(lst)
    while r - l > 1:
        h = (r+l)//2
        if lst[h] > elem: r = h
        else: l = h
    if l == -1:
        print(0)
        exit()
    if lst[l] == elem:
        hr[l] = 1
        hhr[l] = pos
    if l != len(hhl) - 1:
        hhl[l+1] = pos + 1
    return l
mod = 998244353
bnpp = [bnp(b,lstn[i], i) for i in range(n)]
num = 0
if sum(hr) != m:
    print(0)
    exit()
ans = 1
for i in range(1, m):
    if hhr[i] - hhl[i] + 1 <= 0:
        print(0)
        exit()
    ans *= hhr[i] - hhl[i] + 1
    ans %= mod
print(ans)
def sooolve(l,lst, r, x, k, y):
    n = len(lst)
    mx = max(l, r)
    ans = 0
    if n == 0:
        return 0
    if mx < max(lst):
        if n < k:
            return -1
        n -= k
        ans += x
    if x > k * y:
        ans += n * y
    else:
        ans += (n // k) * x + (n % k) * y
    return ans
def solve():
    n, m = map(int,input().split())
    x, k, y = map(int,input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    lastpos = -1
    pos = 0
    ans = 0
    for i in b:
        while pos < n and a[pos] != i:
            pos += 1
        if pos == n:
            print(-1)
            return 0
        if pos != lastpos + 1:
            if lastpos == -1:
                k1 = sooolve(0, a[0:pos], a[pos], x,k,y)
                if k1 == -1:
                    print(k1)
                    return 0
                ans += k1
            else:
                k1 = sooolve(a[lastpos], a[lastpos+1:pos], a[pos], x,k,y)
                if k1 == -1:
                    print(k1)
                    return 0
                ans += k1
        lastpos = pos
    k1 = sooolve(a[lastpos], a[lastpos+1:],0,x,k,y)
    if k1 == -1:
        print(k1)
        return 0
    ans += k1
    print(ans)
for i in range(1):
    solve()
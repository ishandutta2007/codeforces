def pr(lst):
    prr = 1
    for i in lst:
        prr *= i
    return prr
def solve():
    k = int(input())
    l = int(k**(1/10))
    a = [l for i in range(10)]
    st = "codeforces"
    for i in range(10):
        if pr(a) >= k: continue
        a[i] += 1
    for i in range(10):
        print(a[i] * st[i],end="")
for i in range(1):
    solve()
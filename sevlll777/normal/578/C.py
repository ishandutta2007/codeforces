def f(x):
    bi = 0
    ci = 0
    cnt1 = -10 ** 10
    minsum1 = 10 ** 10
    cnt2 = -10 ** 10
    minsum2 = 10 ** 10
    for i in range(len(A)):
        if bi - minsum1 > cnt1:
            cnt1 = bi - minsum1
        if bi <= minsum1:
            minsum1 = bi
        if ci - minsum2 > cnt2:
            cnt2 = ci - minsum2
        if ci <= minsum2:
            minsum2 = ci
        bi += A[i] - x
        ci += x - A[i]
    if bi - minsum1 > cnt1:
        cnt1 = bi - minsum1
    if bi <= minsum1:
        minsum1 = bi
    if ci - minsum2 > cnt2:
        cnt2 = ci - minsum2
    if ci <= minsum2:
        minsum2 = ci
    return max(cnt1, cnt2, 0)


n = int(input())
A = list(map(int, input().split()))
l = min(A)
r = max(A)
for _ in range(70):
    p = l + (r - l) / 3
    q = r - (r - l) / 3
    x = f(p)
    y = f(q)
    if x > y:
        l = p
    elif y > x:
        r = q
    else:
        l = p
        r = q
print(f(l))
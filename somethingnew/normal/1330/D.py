def kr(a, md):
    ans = 1
    for i in a:
        ans *= i
        ans %= mod
    return ans
for t in range(int(input())):
    num, mod = map(int,input().split())
    a = [1] * 31
    step = 1
    hod = 0
    while num > 0:
        if num > step:
            a[hod] += step
            num -= step
        else:
            a[hod] += num
            num = 0
        hod += 1
        step *= 2
    print((kr(a,mod) - 1) % mod)
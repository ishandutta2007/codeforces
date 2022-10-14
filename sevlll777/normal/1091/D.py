n = int(input())
f_n = n
cnt = 0
for k in range(n-1, 0, -1):
    cnt += f_n
    f_n *= k
    if f_n >= 998244353:
        f_n %= 998244353
print((n*f_n-cnt)%998244353)
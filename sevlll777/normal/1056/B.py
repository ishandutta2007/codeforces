n, m = map(int, input().split())
cnt = 0
cnt2 = 0
cnt3 = 0
for i in range(1, m+1):
    for j in range(i+1, m+1):
        if (i**2 + j ** 2) % m == 0:
            cnt += 2
    if (i**2 * 2) % m == 0:
        cnt += 1
for i2 in range(n - n % m + 1, n+1):
    for j2 in range(1, m+1):
        if (i2**2 + j2 ** 2) % m == 0:
            cnt2 += 1
for i3 in range(n - n % m + 1, n+1):
    for j3 in range(i3+1, n+1):
        if (i3**2 + j3 ** 2) % m == 0:
            cnt3 += 2
    if (i3**2 * 2) % m == 0:
        cnt3 += 1
print(cnt*(n//m)**2 + cnt2*2*(n//m)+cnt3)
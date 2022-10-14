n = int(input())
bzz = {}
u = []
for i in range(n):
    m = input().split()
    m = m[1:]
    for elem in m:
        if elem in bzz:
            bzz[elem] += 1
        else:
            bzz[elem] = 1
for k in bzz:
    if bzz[k] == n:
        u.append(k)
print(" ".join(u))
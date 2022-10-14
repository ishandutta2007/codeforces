from math import log
n, k = map(int, input().split())
if n >= k:
    mass_2k = dict()
    while n:
        z = 2**(int(log(n, 2)))
        n -= z
        k -= 1
        if z in mass_2k:
            mass_2k[z] += 1
        else:
            mass_2k[z] = 1
    if k >= 0:
        while k > 0:
            ll = 0
            for b in mass_2k:
                if b > ll and mass_2k[b] != 0:
                    ll = b
            if ll//2 in mass_2k:
                mass_2k[ll // 2] += 2
            else:
                mass_2k[ll // 2] = 2
            k -= 1
            mass_2k[ll] -= 1
        print("YES")
        for u in mass_2k:
            if mass_2k[u]:
                for y in range(mass_2k[u]):
                    print(u, end=" ")
    else:
        print("NO")
else:
    print("NO")
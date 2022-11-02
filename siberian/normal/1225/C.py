def kol(a):
    if a <= 0:
        return -1
    elif a == 1:
        return 1
    elif a % 2 == 1:
        return kol(a // 2) + 1
    else:
        return kol(a // 2)
 
n, p = map(int, input().split())
prov = False
for i in range(1, 1000):
    z = kol(n - i * p)
    if z != -1 and z <= i and n - i * p >= i:
        prov = True
        break
    
if prov:
    print(i)
else:
    print(-1)
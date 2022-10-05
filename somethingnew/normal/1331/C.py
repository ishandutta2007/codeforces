a = str(bin(int(input())))
c = list((8 - len(a)) * '0' + a[2:])
c[1],c[5] = c[5],c[1]
c[2],c[3] = c[3],c[2]
b = c[::-1]
ans = 0
k = 1
for i in b:
    ans += k * int(i)
    k *= 2
print(ans)
n, a, b = [int(i) for i in input().split()]
c = 0
q = [int(i) for i in input().split()]
ans = 0
for i in q:
    if i == 1:
        if a > 0:
            a -= 1
        elif b > 0:
            b -= 1
            c += 1
        elif c > 0:
            c -= 1
        else:
            ans += 1
    else:
        if b > 0:
            b -= 1
        else:
            ans += 2
print(ans)
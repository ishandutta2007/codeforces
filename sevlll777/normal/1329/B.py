aas = []
for _ in range(int(input())):
    d, m = map(int, input().split())
    A = []
    s = 1
    sus = 0
    while sus + s <= d:
        A.append(s)
        sus += s
        s *= 2
    A.append(d - sum(A))
    ans = 1
    for x in A:
        ans *= (x+1)
        ans %= m
    ans -= 1
    ans %= m
    aas.append(str(ans))
print('\n'.join(aas))
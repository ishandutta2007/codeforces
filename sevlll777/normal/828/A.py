n, a, b = map(int, input().split())
T = list(map(int, input().split()))
ans = 0
ca = 0
for d in T:
    if d == 1:
        if a:
            a -= 1
        elif b:
            b -= 1
            ca += 1
        elif ca:
            ca -= 1
        else:
            ans += 1
    else:
        if b:
            b -= 1
        else:
            ans += 2
print(ans)
sd = []
for _ in range(int(input())):
    n, x = map(int, input().split())
    s = input()
    bal = []
    b = 0
    for c in s:
        if c == '0':
            b += 1
        else:
            b -= 1
        bal.append(b)
    ans = 0
    for d in bal:
        if x == d and b == 0:
            ans = -1
            break
        elif b != 0:
            if (x - d) % b == 0 and ((x - d) // b) >= 0:
                ans += 1
    if x == 0 and ans != -1:
        ans += 1
    sd.append(str(ans))
print('\n'.join(sd))
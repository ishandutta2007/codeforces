a, b = map(int, input().split())
if a == b:
    print('infinity')
    exit(0)
x = abs(a - b)
ans = 0
for xx in range(1, int(x**0.5)+1):
    if x % xx == 0:
        if a % xx == b:
            ans += 1
        if xx * xx != x:
            if a % (x//xx) == b:
                ans += 1
print(ans)
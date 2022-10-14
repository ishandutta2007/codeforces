n = int(input())
A = list(map(int, input().split()))
c = sum(A) // n
r = sum(A) % n
lol = n - r
ans = 0
for d in A:
    if lol == 0:
        ans += abs(d - (c+1))
    elif r == 0:
        ans += abs(d - c)
    else:
        if d == c:
            lol -= 1
        elif d > c:
            ans += abs(d - (c+1))
            r -= 1
        else:
            ans += abs(d-c)
            lol -= 1
print(ans//2)
n = int(input())
A = list(map(int, input().split()))
x = A.index(n)
l = x - 1
r = x + 1
now = n - 1
ans = 'YES'
while l >= 0 or r < n:
    if l < 0:
        if A[r] == now:
            now -= 1
            r += 1
        else:
            ans = 'NO'
            break
    elif r >= n:
        if A[l] == now:
            l -= 1
            now -= 1
        else:
            ans = 'NO'
            break
    else:
        if A[l] == now:
            l -= 1
            now -= 1
        elif A[r] == now:
            r += 1
            now -= 1
        else:
            ans = 'NO'
            break
print(ans)
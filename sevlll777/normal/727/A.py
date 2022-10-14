a, b = map(int, input().split())
A = [b]
while b > a:
    if b % 2 == 0:
        b //= 2
    elif b % 10 == 1:
        b //= 10
    else:
        break
    A.append(b)
if A[-1] == a:
    print('YES')
    print(len(A))
    print(*A[::-1])
else:
    print('NO')
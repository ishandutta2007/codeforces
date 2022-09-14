n, x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
if sum(a) + n - 1 == x:
    print('YES')
else:
    print('NO')
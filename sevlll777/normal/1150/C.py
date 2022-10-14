n = int(input())
A = list(map(int, input().split()))
c1 = A.count(1)
c2 = n - c1
if c1 == 0:
    print('2 ' * n)
    exit(0)
if c2 == 0:
    print('1 ' * n)
    exit(0)
print(2, 1, '2 ' * (c2 - 1) + '1 ' * (c1 - 1))
n = int(input())
if n == 2 or n == 3:
    print('Yes')
    exit(0)
c1, c2 = 0, 0
for i in range(n):
    x, y = map(int, input().split())
    if x > 0:
        c1 += 1
    else:
        c2 += 1
if c1 <= 1 or c2 <= 1:
    print('Yes')
else:
    print('No')
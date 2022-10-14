from math import ceil
n, x, y = map(int, input().split())
mass = list(map(int, input().split()))
cnt = 0
if x>y:
    print(len(mass))
else:
    for i in mass:
        if i <= x:
            cnt += 1
    print(ceil(cnt/2))
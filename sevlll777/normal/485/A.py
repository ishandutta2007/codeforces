a, m = map(int, input().split())
pm = set()
while a % m not in pm:
    pm.add(a % m)
    a += a % m
if 0 not in pm:
    print('No')
else:
    print('Yes')
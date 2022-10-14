n = int(input())
tree = {}
for i in range(2, 1 + n):
    q = int(input())
    if q not in tree:
        tree[q] = set()
    tree[q].add(i)
for elem in tree:
    cnt = 0
    for v in tree[elem]:
        if v not in tree:
            cnt += 1
    if cnt < 3:
        print('NO')
        exit(0)
print('YES')
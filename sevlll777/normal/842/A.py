l, r, x, y, k = map(int, input().split())
for J in range(x, y + 1):
    if r >= (k * J) >= l:
        print('YES')
        exit(0)
print('NO')
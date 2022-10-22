n = int(input())
s = input().rstrip()
d = [[1 for i in range(n)] for i in range(n)]
maxx = 0
for i in range(n):
    if s[i] == '.':
        continue
    maxx = max(maxx, max(d[i]))
    for j in range(n):
        if i + j >= n:
            break
        d[i + j][j] = max(d[i + j][j], d[i][j] + 1)
print('yes' if maxx >= 5 else 'no')
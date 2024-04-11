from collections import deque

n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
c50 = sum([1 for i in a if i == 50])
c100 = sum([1 for i in a if i == 100])
c = [[0] * 51 for i in range(51)]
c[0][0] = 1
c[1][0] = 1
c[1][1] = 1
for x in range(2, 51):
    for y in range(x + 1):
        c[x][y] = c[x - 1][y - 1] + c[x - 1][y]
d = [[[[0, float('inf')] for l in range(2)] for i in range(c100 + 1)] for j in range(c50 + 1)]
# d[i][j][c] ,    i  50   j  100      c
d[0][0][0][0] = 1
d[0][0][0][1] = 0
q = deque()
q.append([0, 0, 0])
while len(q) > 0:
    i, j, shore = q.popleft()
    for fifty in range(c50 - i + 1 if shore == 0 else i + 1):
        for hundreds in range(c100 - j + 1 if shore == 0 else j + 1):
            if fifty * 50 + hundreds * 100 > k or fifty + hundreds == 0:
                continue
            i1 = i + fifty if shore == 0 else i - fifty
            j1 = j + hundreds if shore == 0 else j - hundreds
            if d[i1][j1][1 ^ shore][1] > d[i][j][shore][1] + 1:
                d[i1][j1][1 ^ shore][1] = d[i][j][shore][1] + 1
                d[i1][j1][1 ^ shore][0] = 0
                q.append((i1, j1, 1 ^ shore))
            if d[i1][j1][1 ^ shore][1] < d[i][j][shore][1] + 1:
                continue
            koeff = (c[c50 - i][fifty] if shore == 0 else c[i][fifty]) * (
                c[c100 - j][hundreds] if shore == 0 else c[j][hundreds])
            d[i1][j1][1 ^ shore][0] += d[i][j][shore][0] * koeff
            d[i1][j1][1 ^ shore][0] %= 10 ** 9 + 7
if d[c50][c100][1][1] == float('inf'):
    print(-1)
    print(0)
else:
    print(d[c50][c100][1][1])
    print(d[c50][c100][1][0])
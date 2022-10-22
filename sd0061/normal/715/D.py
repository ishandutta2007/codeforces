w = input();
wall = []

p = 39

for i in range(p - 1):
    wall.append((4 + i , 1 + i , 4 + i , 2 + i))
    wall.append((1 + i , 4 + i , 2 + i , 4 + i))
for i in range(p - 2):
    wall.append((6 + i , 1 + i , 6 + i , 2 + i))
    wall.append((1 + i , 6 + i , 2 + i , 6 + i))
for i in range(3):
    wall.append((p + 2 , p + 2 - i , p + 3 , p + 2 - i))
    wall.append((p + 2 - i , p + 2 , p + 2 - i , p + 3))


for i in range(p):
    c = w / (3 ** i) % 3
    if c <= 1:
        wall.append((3 + i , 1 + i , 4 + i , 1 + i))
    if c <= 0:
        wall.append((1 + i , 3 + i , 1 + i , 4 + i))

dp = [[0 for i in range(p + 4)] for j in range(p + 4)]
dp[1][1] = 1

for i in range(1 , p + 4):
    for j in range(1 , p + 4):
        if [i - 1 , j , i , j] not in wall:
            dp[i][j] += dp[i - 1][j]
        if [i , j - 1 , i , j] not in wall:
            dp[i][j] += dp[i][j - 1]
#print dp[p + 3][p + 3]

print p + 3 , p + 3
wall = set(wall)
print len(wall)
for W in wall:
    print W[0], W[1], W[2], W[3]
n, m = (int(s) for s in raw_input().split())

board = []
for i in xrange(n):
    board.append (raw_input())

xlo, xhi, ylo, yhi = 100000, 0, 100000, 0


for i in xrange(n):
    for j in xrange(m):
        if board[i][j] == 'w':
            xlo = min (xlo, i)
            xhi = max (xhi, i)
            ylo = min (ylo, j)
            yhi = max (yhi, j)

def works (x, y):
    if x < 0:
        x = 0
    if y < 0:
        y = 0
    if x + r >= n:
        x = n - r - 1
    if y + r >= m:
        y = m - r - 1
    
    if x < 0 or y < 0 or x + r >= n or y + r >= m:
        return False

    for i in xrange(n):
        for j in xrange(m):
            if board[i][j] == 'w':
                if i == x or i == x + r:
                    if j >= y and j <= y + r:
                        continue
                if j == y or j == y + r:
                    if i >= x and i <= x + r:
                        continue
                return False
    
    for i in xrange(n):
        for j in xrange(m):
            if i == x or i == x + r or j == y or j == y + r:
            	if i >= x and i <= x + r and j >= y and j <= y + r:
                    if board[i][j] != 'w':
                        board[i] = board[i][:j] + '+' + board[i][j+1:]
    
    for i in xrange(n):
        print board[i]
    return True

r = max (xhi - xlo, yhi - ylo)

if works (xlo, ylo):
    pass
elif yhi - ylo < r and works (xlo, yhi - r):
    pass
elif xhi - xlo < r and works (xhi - r, ylo):
    pass
else:
    print -1
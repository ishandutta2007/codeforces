import sys
input=sys.stdin.readline

t = int(input())
for _ in range(t):
    n,m=map(int,input().split())
    table = [list(map(int,input().rstrip())) for _ in range(n)]
    used = [[0] * m for _ in range(n)]
    flg = 0
    for i in range(n):
        for j in range(m):
            if table[i][j] == 1 and used[i][j] == 0:
                if (j > 0 and used[i][j-1]) or (i > 0 and used[i-1][j]):
                    flg = 1
                    break
                used[i][j] = 1
                ni = i
                while ni + 1 < n and table[ni + 1][j]:
                    ni += 1
                    if used[ni][j]:
                        flg = 1
                        break
                    used[ni][j] = 1
                nj = j
                while nj + 1 < m and table[i][nj + 1]:
                    nj += 1
                    if used[i][nj]:
                        flg = 1
                        break
                    used[i][nj] = 1
                if flg:break
                for ii in range(i+1,ni+1):
                    for jj in range(j+1,nj+1):
                        if table[ii][jj]:
                            used[ii][jj] = 1
                        else:
                            flg = 1
                            break
                    if flg:
                        break
                if flg:
                    break
        if flg:
            break
    if flg:
        print('NO')
    else:
        print('YES')
#!/usr/bin/env python3.4

n, m = map(int, input().split())
board = []
for i in range(n):
    board.append(input())
ok_set = set(['f', 'a', 'c', 'e'])
ans = 0
for i in range(n - 1):
    for j in range(m - 1):
        cur_set = set([board[i][j], board[i][j + 1], board[i + 1][j], board[i + 1][j + 1]])
        if cur_set == ok_set:
            ans += 1
print(ans)
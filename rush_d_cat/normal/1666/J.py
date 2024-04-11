import io
import os
import heapq
from collections import deque, Counter


FILE_INPUT_MODE = 0  # 0 for BytesIO, 1 for input.txt, -1 for stdin, input()
if FILE_INPUT_MODE >= 0:

    if FILE_INPUT_MODE == 1:
        CURRENT_DIR = os.path.dirname(os.path.abspath(__file__))
        FD = os.open(f"{CURRENT_DIR}\input.txt", os.O_RDONLY)
    elif FILE_INPUT_MODE == 0:
        FD = 0
    DATA = io.BytesIO(os.read(FD, os.fstat(FD).st_size))
    if FD != 0:
        os.close(FD)

    def input():
        return DATA.readline().decode().rstrip('\r\n')


def solve():
    def get(x1, y1, x2, y2):
        nonlocal s
        return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]

    def dfs(u, v, p):
        nonlocal root, ans
        w = root[u][v]
        ans[w] = p
        if u < w:
            dfs(u, w - 1, w)
        if w < v:
            dfs(w + 1, v, w)
    n = int(input())
    c = [[0 for j in range(n + 1)] for i in range(n + 1)]
    s = [[0 for j in range(n + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        a = [int(word) for word in input().split()]
        for j in range(1, n + 1):
            c[i][j] = a[j - 1]
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + c[i][j]
    dp = [[0 for j in range(n + 1)] for i in range(n + 1)]
    root = [[0 for j in range(n + 1)] for i in range(n + 1)]
    for u in range(1, n + 1):
        for j in range(u, n + 1):
            i = j - u + 1
            dp[i][j] = float('inf')
            for k in range(i, j + 1):
                cur = 0
                if k != i:
                    cur += get(i, 1, k - 1, n) - \
                        get(i, i, k - 1, k - 1) + dp[i][k - 1]
                if k != j:
                    cur += get(1, k + 1, n, j) - \
                        get(k + 1, k + 1, j, j) + dp[k + 1][j]
                if cur < dp[i][j]:
                    dp[i][j] = cur
                    root[i][j] = k
    ans = [-1 for i in range(n + 1)]
    dfs(1, n, 0)
    return " ".join(map(str, ans[1:]))


def main():
    print(solve())


if __name__ == "__main__":
    main()
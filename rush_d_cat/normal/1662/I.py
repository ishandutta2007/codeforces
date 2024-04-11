import io
import os
import heapq
from collections import Counter, deque

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
    inf = float('inf')
    n, m = [int(word) for word in input().strip().split()]
    p = [int(word) for word in input().strip().split()]
    x = [int(word) for word in input().strip().split()]
    q = list(range(0, n * 400, 400))
    for i in range(m):
        x[i] *= 4
    x.sort()
    l = [0 for _ in range(n)]
    r = [0 for _ in range(n)]
    j = 0
    for i in range(n):
        while j < m and x[j] <= q[i]:
            j += 1
        if j == 0:
            l[i] = -inf
        else:
            l[i] = x[j - 1]
    j = m - 1
    for i in range(n - 1, -1, -1):
        while j >= 0 and x[j] >= q[i]:
            j -= 1
        if j == m - 1:
            r[i] = inf
        else:
            r[i] = x[j + 1]
    a = []
    for i in range(n):
        if l[i] == -inf:
            u = -inf
            v = r[i] - 1
        elif r[i] == inf:
            u = l[i] + 1
            v = inf
        else:
            d = min(q[i] - l[i], r[i] - q[i])
            u = max(l[i], q[i] - d)
            v = min(r[i], q[i] + d)
            if u >= v:
                continue
            u += 1
            v -= 1
        # print(i, u, v)
        a.append((u, +p[i]))
        a.append((v + 1, -p[i]))
    # print(a)
    a.sort()
    ans = 0
    cur = 0
    for _, x in a:
        cur += x
        ans = max(ans, cur)
    return ans


def main():
    print(solve())


if __name__ == "__main__":
    main()
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
    mx = 20
    vis = [[False for j in range(360)] for i in range(mx + 1)]
    w1 = [[False for j in range(360)] for i in range(mx + 1)]
    w2 = [[False for j in range(360)] for i in range(mx + 1)]
    n = int(input())
    for i in range(n):
        a = [word for word in input().strip().split()]
        if a[0] == 'C':
            r, t1, t2 = map(int, a[1:])
            while t1 != t2:
                w1[r][t1] = True
                t1 = (t1 + 1) % 360
        else:
            r1, r2, t = map(int, a[1:])
            for j in range(r1, r2):
                w2[j][t] = True
    q = deque()
    for i in range(360):
        vis[mx][i] = True
        q.append((mx, i))
    while len(q) != 0:
        ri, ti = q.popleft()
        if ri == 0:
            return True
        if not w1[ri][ti] and not vis[ri - 1][ti]:
            vis[ri - 1][ti] = True
            q.append((ri - 1, ti))
        if ri < mx and not w1[ri + 1][ti] and not vis[ri + 1][ti]:
            vis[ri + 1][ti] = True
            q.append((ri + 1, ti))
        tn = (ti - 1) % 360
        if not w2[ri][ti] and not vis[ri][tn]:
            vis[ri][tn] = True
            q.append((ri, tn))
        tn = (ti + 1) % 360
        if not w2[ri][tn] and not vis[ri][tn]:
            vis[ri][tn] = True
            q.append((ri, tn))
    return False


def main():
    t = int(input())
    for _ in range(t):
        if solve():
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
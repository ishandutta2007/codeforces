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


def solve(n, m):
    r = 0
    w = 0
    for _ in range(m):
        ri, wi = [int(word) for word in input().strip().split()]
        r = max(r, ri)
        w = max(w, wi)
    if r + w > n:
        return "IMPOSSIBLE"
    w += n - r - w
    return ("R" * r) + ("W" * w)


def main():
    t = int(input())
    for _ in range(t):
        n, m = [int(word) for word in input().strip().split()]
        print(solve(n, m))


if __name__ == "__main__":
    main()
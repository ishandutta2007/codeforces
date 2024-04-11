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


def solve(w, l):
    def check_one(x, p, q):
        if (p - 2) % x == 0 and q % x == 0:
            return True
        if (p - 1) % x == 0:
            if q % x == 0 and (q - 2) % x == 0:
                return True
            if (q - 1) % x == 0:
                return True
        return False

    def check(x):
        nonlocal w, l
        if x > w or x > l:
            return False
        return check_one(x, w, l) or check_one(x, l, w)
    ans = []
    total = ((w - 1) + (l - 1)) * 2
    for i in range(1, total + 1):
        if i * i > total:
            break
        if total % i != 0:
            continue
        j = total // i
        if check(i):
            ans.append(i)
        if i != j and check(j):
            ans.append(j)
    ans.sort()
    ans = [len(ans)] + ans
    return ' '.join(map(str, ans))


def main():
    t = int(input())
    for _ in range(t):
        w, l = [int(word) for word in input().strip().split()]
        print(solve(w, l))


if __name__ == "__main__":
    main()
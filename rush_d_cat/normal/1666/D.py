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


def solve(s, t):
    c = Counter(t)
    ans = []
    for ch in s[::-1]:
        if c[ch] > 0:
            c[ch] -= 1
            ans.append(ch)
    return ''.join(ans[::-1]) == t


def main():
    t = int(input())
    for _ in range(t):
        s, t = [word for word in input().split()]
        if (solve(s, t)):
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()
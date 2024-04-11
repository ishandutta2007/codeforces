#!/usr/bin/python

from sys import stdin

def solve():
    n = int(stdin.readline())
    a = map(int, stdin.readline().split())
    for x in reversed(range(len(a))):
        for v in a:
            good = True
            for b in range(v - x, v + x + 1):
                if b not in a:
                    good = False
            if good:
                return v

if __name__ == "__main__":
    print solve()
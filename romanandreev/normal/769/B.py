#!/usr/bin/python

from sys import stdin

def solve():
    n = int(stdin.readline())
    a = map(int, stdin.readline().split())

    order = sorted(range(n), key=lambda x: (x != 0, -a[x]))

    send_from = 0

    result = []

    for send_to in range(1, n):
        while a[order[send_from]] == 0 and send_from < send_to:
            send_from += 1
        if send_from == send_to:
            return (-1, [])
        result.append((order[send_from] + 1, order[send_to] + 1))
        a[order[send_from]] -= 1

    return (len(result), result)


if __name__ == "__main__":
    l, v = solve()
    print l
    for (a, b) in v:
        print a, b
#!/usr/bin/env python#

import operator as ops

from collections import deque
from itertools import chain


def construct_links(h_and_idx):
    lt_stack = []
    gt_stack = []
    g = [[] for _ in h_and_idx]
    for h, idx in reversed(h_and_idx):
        for stack, cmp_op in [(lt_stack, ops.le), (gt_stack, ops.ge)]:
            prev_h = None
            while stack and cmp_op(h, stack[-1][0]):
                prev_h, prev_idx = stack.pop()
                g[idx].append(prev_idx)
            if stack and prev_h != h:
                g[idx].append(stack[-1][1])
            stack.append((h, idx))
    return g


def main():
    n = int(input())
    h_and_idx = tuple((h, i) for i, h in enumerate(map(int, input().split())))
    g = construct_links(h_and_idx)
    dist = [0] + [-1] * (n - 1)
    q = deque([0], n)
    while q:
        v = q.popleft()
        for x in g[v]:
            if dist[x] == -1:
                dist[x] = dist[v] + 1
                q.append(x)
    print(dist[-1])


if __name__ == '__main__':
    main()
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
    def check_max(x):
        nonlocal n, a, l
        cur = a[1]
        for i in range(1, n):
            if cur > x:
                return False
            cur = max(a[i + 1] - a[i] + cur - x, 0)
        return cur + l - a[n] <= x

    def check_min(x):
        nonlocal n, a, l
        cur = a[1]
        for i in range(1, n):
            if cur + a[i + 1] - a[i] < x:
                return False
            cur = min(cur + a[i + 1] - a[i] - x, a[i + 1] - a[i])
        return True
    l, n = [int(word) for word in input().split()]
    a = [int(word) for word in input().split()]
    a = [0] + a + [l]
    left = 0
    right = l
    while left + 1 < right:
        mid = (left + right) // 2
        if check_max(mid):
            right = mid
        else:
            left = mid
    hi = right
    left = 0
    right = l + 1
    while left + 1 < right:
        mid = (left + right) // 2
        if check_min(mid):
            left = mid
        else:
            right = mid
    lo = left

    graph = [[] for i in range(n + 1)]
    d = [float('inf') for i in range(n + 1)]
    for i in range(0, n):
        graph[i].append((i + 1, hi))
        graph[i + 1].append((i, -lo))
    for i in range(1, n):
        graph[0].append((i, a[i + 1]))
        graph[i].append((n, l - a[i]))
    graph[0].append((n, l))
    d[0] = 0
    q = deque([0])
    vis = {0}
    while len(q) != 0:
        u = q.popleft()
        vis.remove(u)
        for v, cost in graph[u]:
            if d[u] + cost < d[v]:
                d[v] = d[u] + cost
                if v not in vis:
                    vis.add(v)
                    q.append(v)
    # pq = [(d[i], i) for i in range(n + 1)]
    # heapq.heapify(pq)
    # vis = set()
    # while len(pq) != 0:
    #     _, u = heapq.heappop(pq)
    #     if u in vis:
    #         continue
    #     vis.add(u)
    #     for v, cost in graph[u]:
    #         if

    #         for e in self.__graph[u]:
    #             if e.cap > 0 and d[u] + (e.cost + h[u] - h[e.v]) < d[e.v]:
    #                 d[e.v] = d[u] + (e.cost + h[u] - h[e.v])
    #                 back[e.v] = e
    #                 heapq.heappush(pq, (d[e.v], e.v))
    #     if d[t] == float('inf'):
    #         return None
    #     else:
    #         for i in range(self.__n + 1):
    #             h[i] += d[i]
    #         res = []
    #         v = t
    #         while back[v] is not None:
    #             res.append(back[v])
    #             v = back[v].u
    #         return res[::-1]
    ans = []
    for i in range(1, len(d)):
        ans.append(f"{d[i - 1]} {d[i]}")
    return "\n".join(ans)


def main():
    print(solve())


if __name__ == "__main__":
    main()
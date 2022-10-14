def int2bin(n):
    bit_cnt = ''
    while n:
        bit_cnt = str(n & 1) + bit_cnt
        n >>= 1
    return bit_cnt.zfill(70)


n = int(input())
if n <= 2:
    print(-1)
    exit(0)
A = list(map(int, input().split()))
B = []
for i in A:
    B.append(int2bin(i))
graph = {i: set() for i in range(n + 55)}
starts = set()
ans = 10 ** 10
for bit in range(69, -1, -1):
    od = []
    for i in range(n):
        if B[i][bit] == '1':
            od.append(i)
            if len(od) >= 3:
                print(3)
                exit(0)
    if len(od) == 2:
        a, b = od
        graph[a].add(b)
        graph[b].add(a)
        starts.add(a)
        starts.add(b)
for v in starts:
    used = [0] * (n + 55)
    used[v] = 1
    s1 = {v}
    s2 = set()
    c = 0
    par = {}
    while s1:
        c += 1
        for u in s1:
            for j in graph[u]:
                if used[j] == 0:
                    par[j] = u
                    s2.add(j)
                    used[j] = 1
                elif c > 1 and j != v and par[u] != j:
                    if j in s1:
                        ans = min(ans, 2 * c - 1)
                    else:
                        ans = min(ans, 2 * c)
        s1 = s2
        s2 = set()
if ans == 10 ** 10:
    print(-1)
else:
    print(ans)
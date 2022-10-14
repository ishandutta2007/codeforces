n = int(input())
ans = 0
pr = []
hop = {}
for i in range(n):
    a, b, c = list(map(int, input().split()))
    a, b, c = min(a, b, c), a + b + c - min(a, b, c) - max(a, b, c), max(a, b, c)
    if a >= ans:
        ans = a
        pr = [i + 1]
    if (b, c) not in hop:
        hop[(b, c)] = set()
    d = (a, i + 1)
    hop[(b, c)].add(d)
for j in hop:
    if len(hop[j]) > 1:
        max1, max2 = 0, 0
        i1, i2 = 0, 0
        for elem in hop[j]:
            if elem[0] > max2:
                max2 = elem[0]
                i2 = elem[1]
            if max1 < max2:
                i1, i2 = i2, i1
            max1, max2 = max(max1, max2), min(max1, max2)
        ile = min(max1 + max2, j[0], j[1])
        if ans <= ile:
            ans = ile
            pr = [i1, i2]
print(len(pr))
print(*pr)
def solve():
    n = int(input())
    colv = [0 for i in range(8)]
    dct = {}
    for i in list(map(int,input().split())):
        if dct.get(i, False):
            if dct[i] < 8:
                colv[dct[i]] += 1
            if dct[i] < 8:
                colv[dct[i] - 1] -= 1
            dct[i] += 1
        else:
            dct[i] = 1
            colv[0] += 1
    for q in range(int(input())):
        a, b = input().split()
        b = int(b)
        if a == "+":
            if dct.get(b, False):
                if dct[b] < 8:
                    colv[dct[b]] += 1
                if dct[b] < 8:
                    colv[dct[b] - 1] -= 1
                dct[b] += 1
            else:
                dct[b] = 1
                colv[0] += 1
        else:
            dct[b] -= 1
            if dct[b] < 8:
                colv[dct[b]] -= 1
            if dct[b]:
                if dct[b] < 8:
                    colv[dct[b] - 1] += 1
        s = 0
        m4 = False
        for i in range(1, 8):
            s += colv[i] * (i + i % 2)
            if i >= 3 and colv[i]:
                m4 = True
        if m4 and s >= 8:
            print("YES")
        else:
            print("NO")
for i in range(1):
    solve()
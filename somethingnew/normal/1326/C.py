import sys
n, k = map(int,input().split())
lst = list(map(int, input().split()))
ans1 = ((n + n - k + 1) * k) // 2
ans2 = 0
niz = n - k + 1
masr = []
for i in range(len(lst)):
    if lst[i] >= niz:
        sm = 0
        for j in range(i, len(lst)):
            sm += 1
            if lst[j] >= niz:
                masr.append(sm)
                sm = 0
        ans2 = 1
        for j in masr:
            ans2 *= j
        print(ans1, ans2 % 998244353)
        sys.exit()
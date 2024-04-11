n = int(input())
B = list(map(int, input().split()))
A = []
for i in range(100):
    A.append([])
for i in B:
    x = i
    c = 0
    while x % 2 == 0:
        x //= 2
        c += 1
    A[c].append(i)
mlen = 0
f = 1
for lst in A:
    mlen = max(mlen, len(lst))
ans = []
for lst in A:
    if len(lst) == mlen and f:
        f = 0
    else:
        for x in lst:
            ans.append(x)
print(len(ans))
print(' '.join(list(map(str, ans))))
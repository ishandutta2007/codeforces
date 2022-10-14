n, k = map(int, input().split())
A = list(map(int, input().split()))
if n == 1:
    print(A[0])
else:
    s = input()
    hop = dict()
    hop[0] = [A[0]]
    cnt = 0
    if s[0] == s[1]:
        q = 0
    else:
        q = 1
    fl = 1
    for t in range(1, n):
        if s[t] != s[t-1]:
            q += 1
            hop[q] = [A[t]]
        else:
            hop[q].append(A[t])
    for y in hop:
        z = hop[y]
        z = sorted(z, reverse=True)
        if len(z) > k:
            cnt += sum(z[:k])
        else:
            cnt += sum(z)
    print(cnt)
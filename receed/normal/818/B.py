n, m = [int(i) for i in input().split()]
l = [int(i) - 1 for i in input().split()]
ans = [-1] * n
for i in range(m - 1):
    t = (l[i + 1] - l[i]) % n
    if t == 0:
        t = n
    if ans[l[i]] != -1 and ans[l[i]] != t:
        print(-1)
        break
    ans[l[i]] = t
else:
    s = set()
    for i in ans:
        if i != -1:
            s.add(i)
    c = 1
    for i in range(n):
        if ans[i] == -1:
            while c in s:
                c += 1
            ans[i] = c
            s.add(c)

    if len(set(ans)) == n:
        print(' '.join([str(i) for i in ans]))
    else:
        print(-1)
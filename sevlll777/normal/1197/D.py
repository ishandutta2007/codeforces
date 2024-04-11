n, m, k = map(int, input().split())
A = list(map(int, input().split()))
glans = 0
for s in range(m):
    B = []
    f = s
    su = 0
    sus = 0
    for i in range(s, n):
        su += A[i]
        sus = max(sus, su)
        if (i + 1) % m == s:
            B.append(sus - k)
            B.append(su - sus)
            su = 0
            sus = 0
            f = i + 1
    dob = 0
    klol = 0
    for j in range(f, n):
        dob += A[j]
        klol = max(klol, dob - k)
    B = [0] + B + [klol]
    for i in range(1, len(B)):
        B[i] += B[i - 1]
    cnt = -10 ** 10
    ans = [0, 0]
    minsum = 10 ** 10
    candidat = 0
    for i in range(len(B)):
        if B[i] - minsum > cnt:
            cnt = B[i] - minsum
            ans[1] = i
            ans[0] = candidat
        if B[i] <= minsum:
            minsum = B[i]
            candidat = i
    glans = max(glans, B[ans[1]] - B[ans[0]])
print(glans)
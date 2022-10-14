n = int(input())
s = input()
t = input()
A = []
B = []
C = []
D = []
a, b, c, d = 0, 0, 0, 0
for i in range(n):
    f = s[i] + t[i]
    if f == '00':
        d += 1
        D.append(i + 1)
    elif f == '01':
        a += 1
        A.append(i + 1)
    elif f == '11':
        c += 1
        C.append(i + 1)
    else:
        b += 1
        B.append(i + 1)
for x1 in range(a + 1):
    for x2 in range(b + 1):
        if (a + c - x1 - x2) % 2 == 0:
            x3 = (a + c - x1 - x2) // 2
            x4 = n // 2 - x1 - x2 - x3
            if 0 <= x3 <= c and 0 <= x4 <= d:
                ans = []
                for i in range(x1):
                    ans.append(A[i])
                for i in range(x2):
                    ans.append(B[i])
                for i in range(x3):
                    ans.append(C[i])
                for i in range(x4):
                    ans.append(D[i])
                print(' '.join(list(map(str, ans))))
                exit(0)
print(-1)
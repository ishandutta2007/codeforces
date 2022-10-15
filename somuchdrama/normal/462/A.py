n = int(input())
A = []
s = ''
st = ''
for i in range(n + 2):
    st += 'x'
A.append(st)
for i in range(n):
    s = 'x' + input() + 'x'
    A.append(s)
A.append(st)
ans = "YES"
for i in range(1, n + 1):
    for j in range(1, n + 1):
        c = 0
        if A[i + 1][j] == 'o': c += 1
        if A[i - 1][j] == 'o': c += 1
        if A[i][j + 1] == 'o': c += 1
        if A[i][j - 1] == 'o': c += 1
        if c % 2 == 0:
            continue
        else:
            ans = "NO"
            break
print(ans)
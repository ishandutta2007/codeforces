n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
x = A[0][1]
y = A[1][2]
z = A[0][2]
p = (x * y * z) ** 0.5
a1 = p // y
a2 = p // z
a3 = p // x
ans = [round(a1), round(a2), round(a3)]
for i in range(3, n):
    ans.append(round(A[0][i] // a1))
print(' '.join(list(map(str, ans))))
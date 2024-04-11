n = int(input())
A = dict()
A['polycarp'] = 1
for i in range(n):
    a, rep, b = input().split()
    a = a.lower()
    b = b.lower()
    A[a] = A[b] + 1
mx = 1
for i in A:
    mx = max(mx, A[i])
print(mx)
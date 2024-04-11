n = int(input())
A = list(map(int, input().split()))
m = 0
pos = 0
neg = 0
for i in range(n):
    if A[i] < 0:
        neg += 1
        m += (-A[i] - 1)
        A[i] = -1
    elif A[i] > 0:
        pos += 1
        m += (A[i] - 1)
        A[i] = 1
zer = n - pos - neg
if zer:
    print(m + zer)
elif neg % 2 == 0:
    print(m)
else:
    print(m + 2)
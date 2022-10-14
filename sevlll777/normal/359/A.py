n, m = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(n)]
col0, col1 = [], []
for i in A:
    col0.append(i[0])
    col1.append(i[-1])
if A[0][0] + A[-1][-1] == 2 or A[0][-1] + A[-1][0] == 2:
    print(1)
elif 1 in A[0] or 1 in A[-1] or 1 in col0 or 1 in col1:
    print(2)
else:
    print(4)
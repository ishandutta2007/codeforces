na, nb = map(int, input().split())
k, m = map(int, input().split())
A=  list(map(int, input().split()))
B=  list(map(int, input().split()))
if A[k-1] < B[-m]:
    print('YES')
else:
    print('NO')
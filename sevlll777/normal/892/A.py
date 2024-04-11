n = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
B.sort()
if B[-1] + B[-2] >= sum(A):
    print('YES')
else:
    print('NO')
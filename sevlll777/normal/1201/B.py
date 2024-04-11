n = int(input())
A = list(map(int, input().split()))
if sum(A) % 2 == 0 and 2 * max(A) <= sum(A):
    print('YES')
else:
    print('NO')
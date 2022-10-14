n, k = map(int, input().split())
A = list(map(int, input().split()))
Q = max(A)
cnt = 0
power = A[0]
if A[0] == Q:
    print(Q)
    exit(0)
for i in range(1, n):
    if cnt == k:
        print(power)
        exit(0)
    if A[i] == Q:
        print(Q)
        exit(0)
    elif A[i] < power:
        cnt += 1
    else:
        cnt = 1
        power = A[i]
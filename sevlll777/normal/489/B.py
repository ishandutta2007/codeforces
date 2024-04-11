n = int(input())
A = list(map(int, input().split()))
m = int(input())
B = list(map(int, input().split()))
A.sort()
B.sort()
cnt = 0
ua, ub = 0, 0
while ua < n and ub < m:
    if abs(A[ua] - B[ub]) <= 1:
        cnt += 1
        ua += 1
        ub += 1
    else:
        if A[ua] > B[ub]:
            ub += 1
        else:
            ua += 1
print(cnt)
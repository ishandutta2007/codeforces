for _ in range(int(input())):
    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    B.sort()
    k = [B[0] - 1]
    for i in range(1, m):
        if B[i - 1] + 1 == B[i]:
            k.append(B[i] - 1)
        else:
            if k:
                k.append(k[-1] + 1)
                x = A[k[0]:k[-1] + 1]
                x.sort()
                A[k[0]:k[-1] + 1] = x
                k = [B[i] - 1]
    k.append(B[-1] - 1)
    k.append(k[-1] + 1)
    x = A[k[0]:k[-1] + 1]
    x.sort()
    A[k[0]:k[-1] + 1] = x
    if A == sorted(A):
        print('YES')
    else:
        print('NO')
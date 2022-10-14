for _ in range(int(input())):
    n, x = map(int, input().split())
    A = []
    for _1 in range(n):
       d, h = map(int, input().split())
       A.append([d, h])
    A.sort(reverse=True)
    if A[0][0] >= x:
        print(1)
    else:
        x -= A[0][0]
        mz = 0
        for d, h in A:
            mz = max(mz, d - h)
        if mz:
            print((x + mz - 1) // mz + 1)
        else:
            print(-1)
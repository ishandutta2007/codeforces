for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    B = {}
    for i in A:
        if i not in B:
            B[i] = 0
        B[i] += 1
    ans = 'YES'
    J = []
    for i in B:
        if B[i] % 2:
            ans = 'NO'
            break
        else:
            for _ in range(B[i] // 2):
                J.append(i)
    if ans == 'YES':
        J.sort()
        s = set()
        for i in range(n):
            s.add(J[i] * J[-i-1])
        if len(s) != 1:
            ans = 'NO'
    print(ans)
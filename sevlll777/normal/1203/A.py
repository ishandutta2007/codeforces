from collections import deque
for _ in range(int(input())):
    n = int(input())
    A = list(map(int, input().split()))
    ans = 'NO'
    B = deque(A)
    C = [i for i in range(1, n + 1)]
    D = C[::-1]
    for i in range(n):
        B.popleft()
        B.append(A[i])
        if list(B) == C or list(B) == D:
            ans = 'YES'
    print(ans)
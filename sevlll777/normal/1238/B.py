ans = []
for _ in range(int(input())):
    n, r = map(int, input().split())
    A = list(set(list(map(int, input().split()))))
    A.sort(reverse=True)
    c = 0
    for i in range(len(A)):
        if A[i] <= c:
            break
        c += r
    ans.append(str(c // r))
print('\n'.join(ans))
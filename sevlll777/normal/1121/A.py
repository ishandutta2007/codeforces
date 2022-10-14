n, m, k = map(int, input().split())
P = list(map(int, input().split()))
S = list(map(int, input().split()))
C = list(map(int, input().split()))
cnt = 0
for i in C:
    a = P[i - 1]
    b = S[i - 1]
    for j in range(n):
        if S[j] == b and P[j] > a:
            cnt += 1
            break
print(cnt)
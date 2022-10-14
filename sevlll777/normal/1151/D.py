
n = int(input())
S = []
for i in range(n):
    a, b = map(int, input().split())
    S.append([a, b])
S.sort(key=lambda x: (x[1] - x[0]))
cnt = 0
for i in range(n):
    cnt += S[i][0] * i + S[i][1] * (n - i - 1)
print(cnt)
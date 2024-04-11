n = int(input())
M = list(map(int, input().split()))
M.sort()
cnt = 0
for j in range(0, n//2):
    cnt += (M[j] + M[-j - 1])**2
print(cnt)
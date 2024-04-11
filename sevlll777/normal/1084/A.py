n = int(input())
jit = list(map(int, input().split()))
cnt = 0
for u in range(n):
    cnt += jit[u]*4*(u)
print(cnt)
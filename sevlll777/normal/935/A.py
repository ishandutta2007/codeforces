#a, b = map(int, input().split())
n = int(input())
cnt = 0
for l in range(1, n):
    if (n - l) % l == 0:
        cnt += 1
print(cnt)
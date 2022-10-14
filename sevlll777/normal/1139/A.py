n = int(input())
s = list(input())
s = list(map(int, s))
cnt = 0
for i in range(n):
    if s[i] % 2 == 0:
        cnt += i + 1
print(cnt)
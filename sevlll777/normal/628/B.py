s = list(map(int, input()))
cnt = 0
for i in range(len(s) - 1):
    if (s[i] * 2 + s[i + 1]) % 4 == 0:
        cnt += i + 1
    if s[i] % 4 == 0:
        cnt += 1
if s[-1] % 4 == 0:
    cnt += 1
print(cnt)
n = int(input())
s = input()
i = 0
cnt = 0
while i < n - 1:
    if s[i] + s[i + 1] == 'RU' or s[i] + s[i + 1] == 'UR':
        cnt += 1
        i += 1
    i += 1
print(n - cnt)
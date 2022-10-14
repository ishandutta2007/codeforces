n = int(input())
cnt1 = 0
s = input()
for i in range(n):
    if s[i] == '<':
        cnt1 += 1
    else:
        break
for i in range(n - 1, -1, -1):
    if s[i] == '>':
        cnt1 += 1
    else:
        break
print(cnt1)
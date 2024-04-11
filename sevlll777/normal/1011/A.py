n, k = map(int, input().split())
s = list(input())
s.sort()
keka = ord(s[0])
j = 1
cnt = ord(s[0]) - 96
for i in range(1, n):
    if j < k and ord(s[i]) - keka >= 2:
        j += 1
        keka = ord(s[i])
        cnt += ord(s[i]) - 96
if j == k:
    print(cnt)
else:
    print(-1)
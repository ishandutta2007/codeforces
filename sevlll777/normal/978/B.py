n = int(input())
s = input()
s = list(s)
cnt = 0
for j in range(1, n-1):
    if s[j] == s[j-1] == s[j+1] == 'x':
        cnt += 1
print(cnt)
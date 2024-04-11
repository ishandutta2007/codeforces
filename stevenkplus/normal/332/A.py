n = int(input())
s = input()
cnt = 0
for i in range(len(s))[n::n]:
  if s[i-1] == s[i-2] and s[i-1] == s[i-3]:
    cnt += 1
print(cnt)
s = input()
t = input()
for i in range(len(s)):
    if s[i] < t[i]:
        print(-1)
        exit(0)
print(t)
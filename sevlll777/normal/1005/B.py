s = input()
t = input()
cnt = abs(len(s) - len(t))
if len(s) > len(t):
    s = s[len(s) - (len(t)):]
else:
    t = t[(len(t)) - len(s):]
for i in range(len(s) - 1, -1, -1):
    if s[i] != t[i]:
        print(2*(i+1)+cnt)
        exit(0)
print(cnt)
s = input()
f = 0
prya = -1
for i in range(len(s)):
    if f == 0 and s[i] == '[':
        f = 1
    elif f == 1 and s[i] == ':':
        prya = i
        break
prya2 = -1
f = 0
for i in range(len(s) - 1, -1, -1):
    if f == 0 and s[i] == ']':
        f = 1
    elif f == 1 and s[i] == ':':
        prya2 = i
        break
if prya == -1 or prya2 == -1 or prya2 <= prya:
    print(-1)
else:
    print(s[prya:prya2].count('|') + 4)
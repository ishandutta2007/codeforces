s = input()
x = ''
if s[0] == '9':
    x += '9'
else:
    x += str(min(int(s[0]), 9 - int(s[0])))
for i in range(1, len(s)):
    x += str(min(int(s[i]), 9 - int(s[i])))
print(x)
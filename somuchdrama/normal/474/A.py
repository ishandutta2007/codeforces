d = input()
s = input()
A = "qwertyuiopasdfghjkl;zxcvbnm,./"
sout = ''
if d == 'R':
    for i in range(len(s)):
        sout += A[A.find(s[i]) - 1]
else:
    for i in range(len(s)):
        sout += A[A.find(s[i]) + 1]
print(sout)
from sys import *
s=input()
for i in range(1,len(s)):
    if s[i:]==s[:len(s)-i] and i<=(len(s)-1)//2:
        print('YES')
        print(s[i:])
        exit(0)
print('NO')
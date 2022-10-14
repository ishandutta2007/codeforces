n = int(input())
s = input()
s = s[0:-10]
if s.count('8') > (n-11)//2:
    print('YES')
else:
    print('NO')
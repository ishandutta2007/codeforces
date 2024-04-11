s = input()
f = 0
ans = 'YES'
if s.count('b') == 0 or s.count('a') == 0:
    ans = 'NO'
elif s.count('a') != s.count('c') and s.count('b') != s.count('c'):
    ans = 'NO'
else:
    for i in range(len(s)):
        if f == 0:
            if s[i] == 'a':
                pass
            elif s[i] == 'b':
                f = 1
            else:
                ans = 'NO'
        elif f == 1:
            if s[i] == 'b':
                pass
            elif s[i] == 'c':
                f = 2
            else:
                ans = 'NO'
                break
        else:
            if s[i] != 'c':
                ans = 'NO'
                break
print(ans)
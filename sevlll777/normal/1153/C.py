n = int(input())
if n % 2:
    print(':(')
    exit(0)
s = list(input())
ans = ''
c1, c2 = s.count('('), s.count(')')
cnt90 = 0
cnt9, cnt0 = 0, 0
for i in s[:-1]:
    if i == '(':
        cnt90 += 1
        if cnt9 + cnt90 > n // 2:
            print(':(')
            exit(0)
        ans += i
    elif i == ')':
        cnt0 += 1
        if cnt0 > n // 2:
            print(':(')
            exit(0)
        ans += i
    else:
        if cnt9 + c1 < n // 2:
            ans += '('
            cnt9 += 1
        else:
            ans += ')'
            cnt0 += 1
    if cnt90 + cnt9 <= cnt0:
        print(':(')
        exit(0)
if s[-1] == '(' or cnt9 + cnt90 != n // 2:
    print(':(')
    exit(0)
print(ans + ')')
n = int(input())
s = input()
if n % 2:
    print(1)
    print(s)
else:
    if n // 2 != s.count('0'):
        print(1)
        print(s)
    else:
        print(2)
        print(s[0], s[1:])
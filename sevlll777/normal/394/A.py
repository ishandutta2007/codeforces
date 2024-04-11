s = input()
p = s.find('+')
r = s.find('=')
if r - 1 == len(s) - r - 1:
    print(s)
    exit(0)
if abs((r - 1) - (len(s) - r - 1)) != 2:
    print('Impossible')
    exit(0)
if (r - 1) > (len(s) - r - 1):
    if p != 1:
        print(s[1:] + s[0])
    else:
        print('|+' + '|' * (r - 3) + '=' + '|' * (len(s) - r))
else:
    print(s[-1] + s[:-1])
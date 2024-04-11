s = input()
b = s.find('B') % 4
r = s.find('R') % 4
g = s.find('G') % 4
y = s.find('Y') % 4
for x in [r, b, y, g]:
    cnt = 0
    for i in range(x, len(s), 4):
        if s[i] == '!':
            cnt += 1
    print(cnt, end=' ')
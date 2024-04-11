x = input()
l = []
for i in x:
    l.append(min(int(i), 9 - int(i)))

if l[0] == 0:
    l[0] = 9
print(''.join(map(str, l)))
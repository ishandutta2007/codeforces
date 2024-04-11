n = int(input())
hopha = []
for i in range(n):
    s = input()
    hopha.append([len(s), s])
hopha.sort()
fl = 0
for z in range(n-1):
    if hopha[z][1] not in hopha[z+1][1]:
        fl = 1
if fl:
    print('NO')
else:
    print('YES')
    for tt in hopha:
        print(tt[1])
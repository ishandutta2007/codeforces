n = int(input())
f1 = 1
f2 = 1
for i in range(1, 1+n):
    if i == f1 or i == f2:
        if f1 < f2:
            f1 += max(f1, f2)
        else:
            f2 += max(f1, f2)
        print('O', end='')
    else:
        print('o', end='')
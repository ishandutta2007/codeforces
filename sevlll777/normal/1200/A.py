n = int(input())
s = input()
ot = [0] * 10
for i in s:
    if i == 'L':
        for j in range(10):
            if ot[j] == 0:
                ot[j] = 1
                break
    elif i == 'R':
        for j in range(9, -1, -1):
            if ot[j] == 0:
                ot[j] = 1
                break
    else:
        ot[int(i)] = 0
print(''.join(list(map(str, ot))))
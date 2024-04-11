import math

a, b = list(map(int, input().split()))
a = bin(a)[2:]
pos = [a.strip('0'), a.strip('0')[::-1], a+'1', (a+'1')[::-1]]
b = bin(b)[2:]
answer = False
for i in range(4):
    for j in range(len(b)):
        for k in range(len(b)):
            if '1'*j+pos[i]+'1'*k == b:
                answer = True
if answer or a == b:
    print('YES')
else:
    print('NO')
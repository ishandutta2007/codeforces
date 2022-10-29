N = input()
L = list(input().split())
x = 0
for i in (L):
    if ((i[0] == N[0]) or (i[1] == N[1])):
        x = 1
if(x):
    print('YES')
else:
    print('NO')
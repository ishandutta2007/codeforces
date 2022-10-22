n = input()
R = [False for i in range(n)]
C = [False for i in range(n)]
for i in range(n * n):
    x , y = map(int , raw_input().split(' '))
    x -= 1
    y -= 1
    if not R[x] and not C[y]:
        print i + 1,
        R[x] = C[y] = True
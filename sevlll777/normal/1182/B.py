w, h = map(int, input().split())
sas = -4
f = 0
G = 0
U = 0
z = 0
popa = 0
Rer = 0
d1 = 10 ** 4
A = [input().split() for _ in range(w)]
for S in A:
    x = (''.join(S)).find('*')
    y = (''.join(S)).rfind('*')
    if not x == -1:
        for elem in range(x, y+1):
            if S[0][elem] == '.':
                print('NO') 
                exit(0)
    if x == y and not x == -1:
        if G:
            Rer = 1
        z = 1
        popa = 1
        if f:
            print('NO') 
            exit(0) 
        if sas == -4 and U <= x <= d1:
            sas = x
        elif not sas == x:
            print('NO') 
            exit(0)
    elif x == -1 and y == -1:
        if not sas == -4:
            f = 1
    else:
        if z == 0:
            print('NO') 
            exit(0)
        popa = 1
        U, d1 = x, y
        if G:
            print('NO') 
            exit(0)
        G = 1
if popa and d1 - U >= 2 and Rer:
    print('YES')
else:
    print('NO')
t = int(input())
for _ in range(t):
    n = input()
    a = 0
    for i in range(3):
        a += int(n[i])
    b = 0
    for i in range(3,6):
        b += int(n[i])
    if a == b:
        print('YES')
    else:
        print('NO')
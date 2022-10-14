r = int(input())
if r <= 4 or r % 2 == 0:
    print('NO')
elif r % 2 == 1:
    print(1, (r - 3) // 2)
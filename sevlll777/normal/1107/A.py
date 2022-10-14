for i in range(int(input())):
    n = int(input())
    s = input()
    if n != 2 or int(s[0]) < int(s[1]):
        print('YES')
        print(2)
        print(s[0], s[1:])
    else:
        print('NO')
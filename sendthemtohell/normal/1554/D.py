t = int(input())
for _ in range(t):
    n = int(input())
    if n == 1:
        print('a')
    elif n == 2:
        print('ab')
    elif n == 3:
        print('abc')
    elif n % 2 == 0:
        print('a' * (n//2) + 'b' + 'a' * (n//2 - 1))
    else:
        print('a' * (n//2) + 'bc' + 'a' * (n//2 - 1))
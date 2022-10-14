n = int(input())
x = 'aabb'
print(x * (n // 4), end='')
n %= 4
if n == 1:
    print('a')
elif n == 2:
    print('aa')
elif n == 3:
    print('aab')
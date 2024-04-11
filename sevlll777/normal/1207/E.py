from sys import stdout
z = '? '
for i in range(1, 101):
    z += str(128 * i) + ' '
print(z)
ans = 0
c1 = int(input())
stdout.flush()
ans += c1 % 128
z = '? '
for y in range(1, 101):
    z += str(y) + ' '
print(z)
c2 = int(input())
stdout.flush()
ans += c2 - c2 % 128
print('!', ans)
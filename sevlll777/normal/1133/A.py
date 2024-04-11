h1, m1 = list(map(int, input().split(':')))
h2, m2 = list(map(int, input().split(':')))
z = h1 * 60 + m1 + h2 * 60 + m2
z //= 2
print(str(z // 60 // 10) + str(z // 60 % 10) + ':' + str(z % 60 // 10) + str(z % 60 % 10))
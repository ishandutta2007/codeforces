h, m = list(map(int, input().split(':')))
a = int(input())
t = h * 60 + m + a
t %= (24 * 60)
h2 = t // 60
m2 = t % 60
print(str(h2 // 10) + str(h2 % 10) + ':' + str(m2 // 10) + str(m2 % 10))
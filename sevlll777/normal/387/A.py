h1, m1 = map(int, input().split(':'))
h2, m2 = map(int, input().split(':'))
t = h1 * 60 + m1 - h2 * 60 - m2
h = t // 60
h %= 24
m = t % 60
print(str(h // 10) + str(h % 10) + ':' + str(m // 10) + str(m % 10))
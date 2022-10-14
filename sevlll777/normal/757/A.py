s = input()
a1 = s.count('B')
a2 = s.count('u')
a2 //= 2
a3 = s.count('l')
a4 = s.count('b')
a5 = s.count('a')
a5 //= 2
a6 = s.count('s')
a8 = s.count('r')
print(min(a1, a2, a3, a4, a5, a6, a8))
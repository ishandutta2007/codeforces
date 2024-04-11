a='qwertyuiopasdfghjkl;zxcvbnm,./'
b=input()
s=input()

x = lambda c: a[a.index(c) + (1 if b=='L' else -1)]
print(''.join(map(x, s)))
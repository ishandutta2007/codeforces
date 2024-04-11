x, y, z = map(int, input().split())
a = x + z
b = y + z
Q = a >= y
W = b >= x
E = (z==0 and x==y)
if E:
    print(0)
elif Q and W:
     print('?')
elif Q:
     print('+')
else:
     print('-')
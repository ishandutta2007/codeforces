s = input()
t = input()
A = ['monday', 'tuesday', 'wednesday', 'thursday', 'friday', 'saturday', 'sunday']
x = A.index(s) + 1
y = A.index(t) + 1
sos = [31 % 7, 30 % 7, 28 % 7]
if (y - x) % 7 in sos:
    print('YES')
else:
    print('NO')
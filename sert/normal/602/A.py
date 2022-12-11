q = input().split()
n1 = int(q[0])
b1 = int(q[1])
a = input().split()
n1 = 0
for i in range(len(a)):
    a[i] = int(a[i])
    n1 = n1 * b1 + a[i]
    
q = input().split()
n2 = int(q[0])
b2 = int(q[1])
b = input().split()
n2 = 0
for i in range(len(b)):
    b[i] = int(b[i])
    n2 = n2 * b2 + b[i]
    
if n1 < n2:
    print('<')
elif n1 > n2:
    print('>')
else:
    print('=')
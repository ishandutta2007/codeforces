n,a,b = map(int,input().split())
z = 0
q = 0
while a != b:
    z += 1
    a = (a + 1) // 2
    b = (b + 1) // 2
while n != 1:
    n //= 2
    q += 1
if z == q:
    print("Final!")
else:
    print(z)
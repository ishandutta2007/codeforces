n = int(input())
a = []
for i in range(n):
    a.append([])
b = [0] * n
for i in range(n - 1):
    z = int(input())
    b[z - 1] += 1
    a[z - 1].append(i + 1)
z=0
for i in range(n):
    c=0
    for j in range(len(a[i])):
        if b[a[i][j]] == 0:
            c+=1
    if c>=3 or len(a[i]) == 0:
        z+=1
        
#print(a)
#print(b)
#print(z)
if z == n:
    print('Yes')
else:
    print("No")
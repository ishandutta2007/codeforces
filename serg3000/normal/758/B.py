s=input()
n=len(s)
x1=s.find('R') % 4
x2=s.find('B') % 4
x3=s.find('Y') % 4
x4=s.find('G') % 4
k1,k2,k3,k4=0,0,0,0
for i in range(x1,n,4):
    if s[i]=='!':
        k1+=1
for i in range(x2,n,4):
    if s[i]=='!':
        k2+=1
for i in range(x3,n,4):
    if s[i]=='!':
        k3+=1
for i in range(x4,n,4):
    if s[i]=='!':
        k4+=1
print(k1,k2,k3,k4)
a=input()
x=a.find(' ')
s=a[0]
#print(x)
z=0
for i in range(1,x):
    #print(a[i],a[x+1])
    if ord(a[i]) < ord (a[x+1]):
        s+=a[i]
    else:
        s+=a[x+1]
        z=1
        break
if z == 0:
    s+=a[x+1]
print(s)
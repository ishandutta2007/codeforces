s=input()
a=[0]*255
for i in s:
    a[ord(i)]+=1
ans=10**5
for i in 'Blbsr':
    ans=min(ans,a[ord(i)])
for i in 'au':
    ans=min(ans,a[ord(i)]//2)
print(ans)
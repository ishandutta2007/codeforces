n,m=(int(z) for z in input().split())
mas=[int(z) for z in input().split()]
summ=n
summ//=m
ans=0
s=dict()
for i in range(m):
    s[i+1]=0
for i in range(n):
    if mas[i]<=m:
        s[mas[i]]+=1
j=0
i=0
##print(s)
##print(mas)
while i<m:
    while s[i+1]<summ:
        if mas[j]>m:
            mas[j]=i+1
            ans+=1
            s[i+1]+=1
        elif s[mas[j]]>summ:
            s[mas[j]]-=1
            ##print('good')
            mas[j]=i+1
            ans+=1
            ##print ('****',s[i+1],i)
            s[i+1]+=1
            ##print ('*&*',s[i+1])
        ##print(i,j,s[i+1],mas[j])
        j+=1
    i+=1
print(summ,ans)
print(' '.join(str(z) for z in mas))
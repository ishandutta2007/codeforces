n=int(input ())
s=[int(z) for z in input().split ()]
mmx=s[0]
mmn=mmx
ans=0
for i in s:
    if i<mmn:
        mmn=i
        ans+=1
    if i>mmx:
        mmx=i
        ans+=1
print (ans)
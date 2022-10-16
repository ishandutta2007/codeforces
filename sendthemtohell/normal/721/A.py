n=int(input())
s=input()
ans=[]
cu=0
i=0
while i<n:
    if s[i]=="B":
        while i<n and s[i]=="B":
            i+=1
            cu+=1
        ans.append(cu)
        cu=0
    else:
        i+=1
print(len(ans))
for i in ans:
    print (i)
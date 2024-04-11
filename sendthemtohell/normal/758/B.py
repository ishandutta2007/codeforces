s=input()
n=len(s)
res=[0,0,0,0]
for i in range(len(s)):
    if s[i]=="R":
        for j in range(i%4,n,4):
            if s[j]=="!":
                res[0]+=1
        break
for i in range(len(s)):
    if s[i]=="B":
        for j in range(i%4,n,4):
            if s[j]=="!":
                res[1]+=1
        break
for i in range(len(s)):
    if s[i]=="Y":
        for j in range(i%4,n,4):
            if s[j]=="!":
                res[2]+=1
        break
for i in range(len(s)):
    if s[i]=="G":
        for j in range(i%4,n,4):
            #print(s[j])
            if s[j]=="!":
                res[3]+=1
        break
print(" ".join([str(z) for z in res]))
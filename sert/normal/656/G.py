n,m,t=input().split()
n,m,t=int(n),int(m),int(t)
ans=0
s=[]
#kitten
for i in range(n):
    s.append(input())
for j in range(m):
    c = 0
    for i in range(n):
        c += s[i][j] == 'Y'
    if c >= t:
        ans+=1
print(ans)
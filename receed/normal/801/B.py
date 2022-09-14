x=input()
y=input()
n=len(x)
ans=[]
f=1
for i in range(n):
    if x[i]>=y[i]:
        ans.append(y[i])
if len(ans)==n:
    print(''.join(ans))
else:
    print(-1)
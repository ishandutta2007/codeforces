s=input()
x=0
for i in range(len(s)//2):
    if s[i]!=s[-1-i]:
        x+=1
if x==1 or x==0 and len(s)%2:
    print('YES')
else:
    print('NO')
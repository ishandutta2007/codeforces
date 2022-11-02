n=int(input())
s=input()
c=0
for i in range(n):
    if s[i]=='A':
        c+=1
if c==n/2:
    print('Friendship')
else:
    if c>n/2:
        print('Anton')
    else:
        print('Danik')
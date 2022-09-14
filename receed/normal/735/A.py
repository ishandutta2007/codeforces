n,k=[int(i) for i in input().split()]
s=input()
f=s.find('G')
t=s.find('T')
if f<t:
    f,t=t,f
if (f-t)%k:
    print('NO')
else:
    for i in range(t+k,f,k):
        if s[i]=='#':
            print('NO')
            break
    else:
        print('YES')
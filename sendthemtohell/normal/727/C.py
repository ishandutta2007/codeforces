def ask(i,j):
    print("?",i+1,j+1)
    return int(input())

n=int(input())
s=[0]*n
while n:
    if n==4:
        a=ask(0,1)
        b=ask(1,2)
        c=ask(2,3)
        d=ask(0,2)
        s[0]=(a+d-b)//2
        s[1]=(a+b-d)//2
        s[3]=a+c-b-s[0]
        s[2]=b-s[1]
        n=0
    elif n==5:
        a=ask(0,1)
        b=ask(1,2)
        c=ask(2,3)
        d=ask(0,2)
        e=ask(0,4)
        s[0]=(a+d-b)//2
        s[1]=(a+b-d)//2
        s[3]=a+c-b-s[0]
        s[2]=b-s[1]
        s[4]=e-s[0]
        n=0
    else:
        a=ask(n-1,n-2)
        b=ask(n-2,n-3)
        c=ask(n-1,n-3)
        s[n-1]=(a+c-b)//2
        s[n-2]=(a+b-c)//2
        s[n-3]=(b+c-a)//2
        n-=3
print("!",' '.join(map(str,s)))
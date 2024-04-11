import sys
n=input()
s=raw_input()
c1=c2=0
for i in range(0,n):
    if s[i]=='x':
        c1=c1+1
    else:
        c2=c2+1
if (c1<c2):
    print (c2-c1)/2
    for i in range(0,n):
        if (s[i]=='x'):
            sys.stdout.write('x')
        elif (c2>c1):
            c2=c2-1
            c1=c1+1
            sys.stdout.write('x')
        else:
            sys.stdout.write('X')
else:
    print (c1-c2)/2
    for i in range(0,n):
        if (s[i]=='X'):
            sys.stdout.write('X')
        elif (c2<c1):
            c2=c2+1
            c1=c1-1
            sys.stdout.write('X')
        else:
            sys.stdout.write('x')
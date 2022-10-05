from math import gcd
def ans(numa,numb,gran):
    return (gran//numa)*numb + min(gran%numa,numb)
for t in range(int(input())):
    a,b,q=map(int,input().split())
    num1 = gcd(a, b)
    num2 = a*b//num1
    num3 = max(a,b)
    if a%b==0 or b%a==0:
        for i in range(q):
            input()
        print('0 ' * q)
    else:
        for i in range(q):
            l,r = map(int,input().split())
            arra = ans(num2,num3,r+1)-ans(num2,num3,l)
            print(r-l-arra+1,end=' ')
        print()
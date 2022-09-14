n=int(input())
if n==0:
    print(1)
else:
    k=n%4+4
    print(8**k%10)
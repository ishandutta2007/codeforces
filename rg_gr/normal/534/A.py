n=int(input())

if(n==2):
    print("1\n1")
elif(n==3):
    print("2\n1 3")
elif n==4:
    print("4\n3 1 4 2")
elif(n==1):
    print("1\n1")
else:
    print(n)
    for i in range(1,n+1,2):
        print(i,end=' ')
    for i in range(2,n+1,2):
        print(i,end=' ')
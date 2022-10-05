for t in range(int(input())):
    n = int(input())
    if n % 4 == 2:
        print("NO")
    else:
        print('YES')
        k = n//2
        num1 = k * k + k
        num2 = (k-1)*(k-1)
        num3 = num1 - num2
        a1=list(range(2,k*2+2,2))
        a2= list(range(1,k*2-1,2))
        print(*a1,*a2,num3)
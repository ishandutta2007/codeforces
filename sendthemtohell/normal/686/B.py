def f(arr,n):
    for i in range(n,1,-1):
        for j in range(1,i):
            if arr[j]<arr[j-1]:
                print(j,j+1)
                arr[j],arr[j-1]=arr[j-1],arr[j]

n=int(input())
a=[int(z) for z in input().split()]
f(a,n)
n=int(input())
a=[int(i) for i in input().split()]
k,l=a.index(1),a.index(n)
print(max(k,l,n-k-1,n-l-1))
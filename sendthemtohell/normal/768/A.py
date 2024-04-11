n=int(input())
a=[int(z) for z in input().split()]

a.sort()

i=0
while i<n and a[i]==a[0]:
    i+=1
j=n-1
while j>=0 and a[j]==a[-1]:
    j-=1
print(max(0,j-i+1))
n=int(input ())
s=[[int(z),0] for z in input().split()]
for i in range(n):
    s[i][1]=i+1
s.sort()
for i in range(n//2):
    print(s[i][1],s[n-i-1][1])
a,b=map(int,input().split())
c=1
for i in range(b-a):
    z=(a + i + 1) % 10
    c*=z
    c=c%10
    if c==0:
        break
    
print(c)
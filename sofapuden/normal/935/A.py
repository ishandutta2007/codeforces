N = int(input())
x = 0
for i in range(1,N//2+1):
    if(N%i == 0):
        x+= 1
print(x)
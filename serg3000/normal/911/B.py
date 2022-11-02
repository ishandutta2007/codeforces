n,a,b=map(int,input().split())
for i in range(1,a + b + 1):
    if a // i + b // i < n:
        print(min(i - 1,a,b))
        break
n=int(input())
m=int(input())
if n > 1000:
    print(m)
else:
    print(m % (2 ** n))
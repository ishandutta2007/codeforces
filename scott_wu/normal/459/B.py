n = int(input())
x = list(map(int, input().split()))
a = max(x)
b = min(x)
c = sum(1 for m in x if m == a)
d = sum(1 for m in x if m == b)

if a == b:
    print(str(0) + " " + str(n*(n-1)//2))
else:
    print(str(a-b) + " " + str(c*d))
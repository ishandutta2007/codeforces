n, k = map(int, input().split())
for i in range(k):
    if n % 10:
        n -=1
    else:
        n//=10
print(n)
a = int(input())
b = int(input())
k = a - b
if k % 2:
    print(-1)
    exit(0)
k >>= 1
if k < 0:
    print(-1)
    exit(0)
print(k, a - k)
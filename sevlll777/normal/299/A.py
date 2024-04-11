n = int(input())
A = list(map(int, input().split()))
m = min(A)
for x in A:
    if x % m:
        print('-1')
        exit(0)
print(m)
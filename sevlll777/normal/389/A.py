from math import gcd
n = int(input())
A = list(map(int, input().split()))
j = A[0]
for i in A:
    j = gcd(j, i)
print(j * n)
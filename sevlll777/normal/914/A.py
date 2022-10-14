n = int(input())
A = list(map(int, input().split()))
kk = float('-inf')
for t in A:
    if t > kk and (t < 0 or t**0.5 % 1 != 0):
        kk = t
print(kk)
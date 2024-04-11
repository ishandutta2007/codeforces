n = int(input())
A = list(map(int, input().split()))
v1 = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
v2 = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
v = v1 + v1 + v1 + v2 + v1 + v1 + v1
for i in range(len(v) - n + 1):
    if A == v[i:i+n]:
        print('Yes')
        exit(0)
print('No')
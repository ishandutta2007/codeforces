n = int(input())
a = list(map(int, input().split()))
a = a[::-1]
d = 0
for i in range(len(a)):
    d = max(0 + d, a[i] + (sum(a[:i]) - d))
print(sum(a)-d, d)
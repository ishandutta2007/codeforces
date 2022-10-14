n = int(input())
ab = 0
for i in range(n):
    x, y = map(float, input().split())
    ab += y
print(5 + ab / n)
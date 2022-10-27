t = int(input())
for iter in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    print(max(a) - min(a))